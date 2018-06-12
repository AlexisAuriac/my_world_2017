/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Handles keyboard interactions using ctrl.
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "interactions.h"

int keyboard_o(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		map_reload(map, window);
	return (0);
}

int keyboard_s(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		map_save(map, window);
	return (0);
}

int keyboard_n(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		map_new(map, window);
	return (0);
}

int keyboard_e(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		enlarge_map(map, window);
	return (0);
}

int keyboard_r(map_t *map, sfEvent *event,
	UNUSED int *mode, sfRenderWindow *window)
{
	if (event->key.control)
		reduce_map(map, window);
	return (0);
}