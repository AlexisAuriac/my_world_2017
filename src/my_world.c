/*
** EPITECH PROJECT, 2018
** my_world.c (my_world)
** File description:
** heart of my_world project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"

int my_world(const char *file)
{
	map_t map = DEFAULT_MAP;

	if (!map_create(&map, file))
		return (84);
	game_loop(&map);
	map_destroy(&map);
	return (0);
}
