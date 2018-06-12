/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Creates the map with the help of the loading map functions.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "map.h"

sfVector2f **create_2d_map(map_t *map)
{
	sfVector2f **map2 = malloc(sizeof(sfVector2f *) * map->size.y);

	if (map2 == NULL) {
		my_puterr("Malloc failed\n");
		return (NULL);
	}
	for (int i = 0 ; i < map->size.y ; ++i) {
		map2[i] = malloc(sizeof(sfVector2f) * map->size.x);
		if (map2[i] == NULL) {
			while (i--)
				free(map2[i]);
			free(map2);
			my_puterr("Malloc failed\n");
			return (NULL);
		}
	}
	return (map2);
}

bool map_create(map_t *map, const char *file)
{
	if (file == NULL) {
		map->d3 = init_3d_map(&map->size);
		if (map->d3 == NULL)
			return (false);
	}
	else if (!map_load(map, file)) {
		map_destroy(map);
		return (false);
	}
	map->d2 = create_2d_map(map);
	if (map->d2 == NULL) {
		map_destroy(map);
		return (false);
	}
	project_3d(map);
	map->view = sfView_createFromRect((sfFloatRect) {0, 0, WIDTH, HEIGHT});
	return (true);
}
