/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Header for map.
*/

#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <math.h>

typedef struct point {
	int height;
	short int mat;
}point_t;

typedef struct map {
	sfVector2i size;
	point_t **d3;
	float zoom;
	sfVector2f **d2;
	sfView *view;
	void (*modif)(point_t *);
}map_t;

typedef enum {
	HOR,
	VER
}axis_t;


static const double ANGLE_X = 45 * M_PI / 180;
static const double ANGLE_Y = 30 * M_PI / 180;

static const double SCALING_X = 60.0;
static const double SCALING_Y = 60.0;
static const double SCALING_Z = 15.0;

static const int OFFSET_X = 640;
static const int OFFSET_Y = 360;

static const int MAX_HEIGHT = 10;
static const int MIN_HEIGHT = -10;

static const int CORNER_RADIUS = 10;

static const int MAP_MAX_SIZE = 32;

void interactions_map_raise(point_t *point);

static const map_t DEFAULT_MAP = {
	.size.x = 10,
	.size.y = 10,
	.zoom = 1.0,
	.d3 = NULL,
	.d2 = NULL,
	.view = NULL,
	.modif = interactions_map_raise
};


point_t **load_3d(map_t *, int);
point_t **init_3d_map(sfVector2i *);
bool map_load(map_t *, const char *);
void map_reload(map_t *map, sfRenderWindow *);
void map_save(map_t *map, sfRenderWindow *);
int **map_d3_create(int width, int height);
bool map_create(map_t *map, const char *);
void map_destroy(map_t *);
void rotate_map(map_t *, int, axis_t);
void project_3d(map_t *);
sfVertexArray *create_line(sfVector2f *, sfVector2f *);
sfVector2f **create_2d_map(map_t *);
void draw_2d_map(sfRenderWindow *, map_t *);
void map_new(map_t *, sfRenderWindow *);
void enlarge_map(map_t *, sfRenderWindow *);
void reduce_map(map_t *, sfRenderWindow *);

#endif
