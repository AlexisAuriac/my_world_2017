/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Handles interactions with the map.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "map.h"

void interactions_map_raise(point_t *point)
{
	if (point->height > MAX_HEIGHT)
		return;
	++point->height;
}

void interactions_map_lower(point_t *point)
{
	if (point->height < MIN_HEIGHT)
		return;
	--point->height;
}

void interactions_map_level(point_t *point)
{
	point->height = 0;
}

bool on_point(sfVector2f pos, sfVector2f point)
{
	if (pos.x < point.x - CORNER_RADIUS || pos.x > point.x + CORNER_RADIUS)
		return (false);
	if (pos.y < point.y - CORNER_RADIUS || pos.y > point.y + CORNER_RADIUS)
		return (false);
	return (true);
}

void interactions_click_map(map_t *map, sfEvent *event, sfRenderWindow *window)
{
	sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};
	sfVector2f pos = {0};

	pos = sfRenderWindow_mapPixelToCoords(window, mouse, map->view);
	for (int i = map->size.y - 1 ; i >= 0 ; --i) {
		for (int j = 0 ; j < map->size.x ; ++j) {
			if (on_point(pos, map->d2[i][j])) {
				map->modif(&map->d3[i][j]);
				project_3d(map);
				return;
			}
		}
	}
}