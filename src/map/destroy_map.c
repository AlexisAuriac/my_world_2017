/*
** EPITECH PROJECT, 2018
** destroy_map.c (my_world)
** File description:
** all functions needed to destroy a map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "map.h"

void destroy_2d_map(sfVector2f **d2, sfVector2i *size)
{
	for (int i = 0; i < size->y; ++i) {
		if (d2[i] != NULL)
			free(d2[i]);
	}
	free(d2);
}

void destroy_3d_map(point_t **d3, sfVector2i *size)
{
	for (int i = 0; i < size->y; ++i) {
		if (d3[i] != NULL)
			free(d3[i]);
	}
	free(d3);
}

void map_destroy(map_t *map)
{
	if (map->d2 != NULL)
		destroy_2d_map(map->d2, &map->size);
	if (map->d3 != NULL)
		destroy_3d_map(map->d3, &map->size);
	sfView_destroy(map->view);
}
