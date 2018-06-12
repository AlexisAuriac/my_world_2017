/*
** EPITECH PROJECT, 2018
** load_3d_map.c (my_world)
** File description:
** load the 3d map from a file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "prompt.h"
#include "map.h"

void destroy_when_failed(point_t **map_3d, int i)
{
	while (i--)
		free(map_3d[i]);
	free(map_3d);
	my_puterr("Malloc failed\n");
}

point_t **init_3d_map(sfVector2i *size)
{
	point_t **map_3d = malloc(sizeof(point_t *) * size->y);

	if (map_3d == NULL) {
		my_puterr("Malloc failed\n");
		return (NULL);
	}
	for (int i = 0 ; i < size->y ; ++i) {
		map_3d[i] = malloc(sizeof(point_t) * size->x);
		if (map_3d[i] == NULL) {
			destroy_when_failed(map_3d, i);
			return (NULL);
		}
		for (int j = 0; j < size->x; ++j) {
			map_3d[i][j].height = 0;
			map_3d[i][j].mat = 1;
		}
	}
	return (map_3d);
}

point_t **load_3d(map_t *map, int fd_save)
{
	point_t **map_3d = init_3d_map(&map->size);

	if (map_3d == NULL)
		return (NULL);
	for (int y = 0; y < map->size.y ; ++y) {
		for (int x = 0; x < map->size.x; ++x) {
			read(fd_save, &map_3d[y][x].height, sizeof(int));
			read(fd_save, &map_3d[y][x].mat, sizeof(short int));
		}

	}
	return (map_3d);
}
