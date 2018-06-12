/*
** EPITECH PROJECT, 2018
** bootstrap my world
** File description:
** Draws the 2d map.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "map.h"

void project_3d(map_t *map)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int offset_x = (map->size.x - 1) * (SCALING_X / 2);
	int offset_y = (map->size.y - 1) * (SCALING_Y);

	for (int i = 0 ; i < map->size.y ; ++i) {
		for (int j = 0 ; j < map->size.x ; ++j) {
			x = i * SCALING_X;
			y = j * SCALING_Y;
			z = map->d3[i][j].height * SCALING_Z;
			map->d2[i][j].x = cos(ANGLE_X) * x -
				sin(ANGLE_X) * y;
			map->d2[i][j].x += (WIDTH / 2) + sin(ANGLE_X) *
				offset_x - cos(ANGLE_X) * offset_x;
			map->d2[i][j].y = sin(ANGLE_Y) * (y + x) - z;
			map->d2[i][j].y += (HEIGHT / 2) - offset_y *
				sin(ANGLE_Y);
		}
	}
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

void draw_2d_map(sfRenderWindow *window, map_t *map)
{
	sfVertexArray *line = NULL;
	sfVector2f size = {WIDTH * map->zoom, HEIGHT * map->zoom};

	sfView_setSize(map->view, size);
	sfRenderWindow_setView(window, map->view);
	for (int i = 0 ; i < map->size.y ; ++i) {
		for (int j = 0 ; j < map->size.x - 1 ; ++j) {
			line = create_line(&map->d2[i][j], &map->d2[i][j + 1]);
			sfRenderWindow_drawVertexArray(window, line, 0);
			sfVertexArray_destroy(line);
		}
	}
	for (int i = 0 ; i < map->size.x ; ++i) {
		for (int j = 0 ; j < map->size.y - 1 ; ++j) {
			line = create_line(&map->d2[j][i], &map->d2[j + 1][i]);
			sfRenderWindow_drawVertexArray(window, line, 0);
			sfVertexArray_destroy(line);
		}
	}
	sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
}
