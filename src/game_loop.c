/*
** EPITECH PROJECT, 2017
** disp_window.c
** File description:
** functions required to dispplay a window
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "interactions.h"
#include "prompt.h"

void actualize_window(sfRenderWindow *window, map_t *map,
		interactions_t *interactions)
{
	sfEvent event = {0};

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (type_interaction[event.type] != NULL) {
			type_interaction[event.type]
			(map, &event, interactions, window);
		}
	}
	sfRenderWindow_clear(window, sfBlack);
	draw_2d_map(window, map);
	button_display(window, interactions->buttons, event);
	sfRenderWindow_display(window);
}

int game_loop(map_t *map)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *window = NULL;
	interactions_t interactions;

	window = sfRenderWindow_create(mode, "my_world",
				sfFullscreen | sfClose, NULL);
	if (window == NULL)
		return (84);
	init_interactions(&interactions);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE);
	while (sfRenderWindow_isOpen(window)) {
		actualize_window(window, map, &interactions);
	}
	button_destroy(interactions.buttons);
	sfRenderWindow_destroy(window);
	return (0);
}
