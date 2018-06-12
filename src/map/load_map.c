/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Loads the map given as argument into a 3d map.
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "prompt.h"
#include "map.h"

bool map_load(map_t *map, const char *file_name)
{
	int fd_save = open(file_name, O_RDONLY);

	if (fd_save == -1) {
		my_puterr("Can't open map\n");
		return (false);
	}
	if (read(fd_save, &map->size.y, sizeof(int)) < 4 ||
	read(fd_save, &map->size.x, sizeof(int)) < 4) {
		my_puterr("Invalid map\n");
		return (false);
	}
	else if (map->size.x <= 0 || map->size.y <= 0) {
		my_putstr("Invalid map\n");
		return (false);
	}
	map->d3 = load_3d(map, fd_save);
	close(fd_save);
	if (map->d3 == NULL)
		return (false);
	return (true);
}

void map_reload(map_t *map, sfRenderWindow *window)
{
	map_t new_map = DEFAULT_MAP;
	char *new_file = NULL;

	new_file = graph_prompt(window);
	if (new_file == NULL) {
		return;
	}
	if (!map_create(&new_map, new_file)) {
		free(new_file);
		return;
	}
	free(new_file);
	map_destroy(map);
	*map = new_map;
}