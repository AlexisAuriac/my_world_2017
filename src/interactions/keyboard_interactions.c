/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Handles user interactions with the program using a keyboard.
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "interactions.h"

int keyboard_escape(UNUSED map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	return (0);
}

int keyboard_page_up(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	map->zoom -= 0.03;
	return (0);
}

int keyboard_page_down(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	map->zoom += 0.03;
	return (0);
}