/*
** EPITECH PROJECT, 2018
** keyboard_interactions.c (my_world)
** File description:
** heart of the user's interaction management
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_world.h"
#include "interactions.h"

int interactions_closed(UNUSED map_t *map, UNUSED sfEvent *event,
	UNUSED interactions_t *interactions, sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	return (0);
}

int interactions_keypressed(map_t *map, sfEvent *event,
	interactions_t *interactions, UNUSED sfRenderWindow *window)
{
	if (event->key.code < 0)
		return (-1);
	else if (interactions->keyboard_interaction[event->key.code] == NULL) {
		return (-1);
	}
	return (interactions->keyboard_interaction[event->key.code]
		(map, event, NULL, window));
}

int interaction_mouse_released(map_t *map, sfEvent *event,
	interactions_t *interactions, sfRenderWindow *window)
{
	button_t *current = interactions->buttons;
	sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};

	if (event->mouseButton.button == sfMouseLeft) {
		while (current != NULL) {
			if (in_bounds(mouse, current->pos, current->rect)) {
					current->ptr(map, window);
				return (0);
			}
			current = current->next;
		}
		interactions_click_map(map, event, window);
	}
	return (0);
}