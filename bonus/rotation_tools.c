/*
** EPITECH PROJECT, 2018
** rotation_tools.h (my_world)
** File description:
** all functions needed to rotate the map
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "map.h"
#include "my_world.h"
#include "map.h"

void rotate_map(map_t *map, int rot, axis_t axis)
{
	if (axis == HOR)
		map->angle.x = fmodf(map->angle.x, 2 * M_PI) + DTR(rot);
	else
		map->angle.y = fmodf(map->angle.y, 2 * M_PI) + DTR(rot);
	project_3d(map);
}

int rotate_left(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	rotate_map(map, -3, HOR);
	return (0);
}

int rotate_right(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	rotate_map(map, 3, HOR);
	return (0);
}

int rotate_down(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	if (map->angle.y > -(M_PI / 6)) {
		rotate_map(map, -3, VER);
		return (0);
	} else
		return (-1);
}

int rotate_up(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	if (map->angle.y < (M_PI / 6)) {
		rotate_map(map, 3, VER);
		return (0);
	} else
		return (-1);
}
