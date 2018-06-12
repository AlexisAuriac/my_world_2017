/*
** EPITECH PROJECT, 2018
** modify_mapsize.c (my_world)
** File description:
** all functions modify the size of the map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "map.h"

int generate_new_2d_map(map_t *map, sfVector2i *new_size,
	UNUSED sfRenderWindow *window)
{
	for (int i = 0; i < map->size.y ; ++i)
		free(map->d2[i]);
	free(map->d2);
	map->size.x = new_size->x;
	map->size.y = new_size->y;
	map->d2 = create_2d_map(map);
	if (map->d2 == NULL)
		return (84);
	project_3d(map);
	return (0);
}

void reduce_map(map_t *map, UNUSED sfRenderWindow *window)
{
	sfVector2i new_size = {map->size.x - 1, map->size.y - 1};
	point_t **new_map_3d = NULL;
	int i = 0;

	if (new_size.x < 2 || new_size.y < 2)
		return;
	new_map_3d = init_3d_map(&new_size);
	if (new_map_3d == NULL)
		return;
	for (; i < new_size.y; ++i) {
		for (int j = 0; j < new_size.x; ++j) {
			new_map_3d[i][j].height = map->d3[i][j].height;
			new_map_3d[i][j].mat = map->d3[i][j].mat;
		}
		free(map->d3[i]);
	}
	free(map->d3[i]);
	free(map->d3);
	map->d3 = new_map_3d;
	generate_new_2d_map(map, &new_size, window);
}

void enlarge_map(map_t *map, UNUSED sfRenderWindow *window)
{
	sfVector2i new_size = {map->size.x + 1, map->size.y + 1};
	point_t **new_map_3d = NULL;

	if (new_size.x > MAP_MAX_SIZE || new_size.y > MAP_MAX_SIZE)
		return;
	new_map_3d = init_3d_map(&new_size);
	if (new_map_3d == NULL)
		return;
	for (int i = 0; i < new_size.y; ++i) {
		for (int j = 0; j < new_size.x; ++j) {
			if (j < map->size.x && i < map->size.y) {
				new_map_3d[i][j].height = map->d3[i][j].height;
				new_map_3d[i][j].mat = map->d3[i][j].mat;
			}
		}
		if (i < map->size.y)
			free(map->d3[i]);
	}
	free(map->d3);
	map->d3 = new_map_3d;
	generate_new_2d_map(map, &new_size, window);
}
