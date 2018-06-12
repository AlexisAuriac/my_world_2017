/*
** EPITECH PROJECT, 2018
** bootstrap my world
** File description:
** Basic functions of the map struct.
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "map.h"
#include "my_world.h"
#include "prompt.h"

void map_save(map_t *map, sfRenderWindow *window)
{
	char *file = graph_prompt(window);
	int save = -1;

	if (file == NULL)
		return;
	save = open(file, O_WRONLY | O_CREAT | O_TRUNC, 436);
	if (save == -1) {
		my_puterr("Couldn't open save file\n");
		return;
	}
	write(save, &map->size.y, sizeof(int));
	write(save, &map->size.x, sizeof(int));
	for (int i = 0 ; i < map->size.y ; ++i) {
		for (int j = 0 ; j < map->size.x ; ++j) {
			write(save, &map->d3[i][j].height, sizeof(int));
			write(save, &map->d3[i][j].mat, sizeof(short int));
		}
	}
	close(save);
	my_putstr("Map saved\n");
}

void map_new(map_t *map, UNUSED sfRenderWindow *window)
{
	map_t new_map = DEFAULT_MAP;

	if (!map_create(&new_map, NULL))
		return;
	map_destroy(map);
	*map = new_map;
}