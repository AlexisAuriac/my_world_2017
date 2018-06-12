/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Handles keyboard interactions using ctrl (second file).
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "interactions.h"

int keyboard_equal(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		button_level(map, window);
	return (0);
}

int keyboard_u(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		button_raise(map, window);
	return (0);
}

int keyboard_d(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		button_lower(map, window);
	return (0);
}