/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Header file for buttons.
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include "map.h"

typedef enum {
	IDLE=0,
	HOVER=1,
	CLICKED=2
}bstate_t;

typedef struct info {
	sfFont *font;
	sfText *text;
	sfFloatRect rect;
}info_t;

typedef struct button {
	sfVector2f pos;
	info_t *info;
	void (*ptr)(map_t *, sfRenderWindow *window);
	sfIntRect rect;
	bstate_t state;
	sfTexture *texture;
	sfSprite *sprite;
	struct button *next;
}button_t;

typedef struct param_button {
	sfVector2f position;
	char *file;
	char *info;
	void (*ptr)(map_t *, sfRenderWindow *);
}param_button_t;


static const int BUTTON_WIDTH = 100;
static const int BUTTON_HEIGHT = 100;
static const int NB_BUTTON = 8;

void button_raise(map_t *, sfRenderWindow *);
void button_lower(map_t *, sfRenderWindow *);
void button_level(map_t *, sfRenderWindow *);

static const param_button_t init_button[] = {
	{.position = {0, 1080 - 100},
	.file = "assets/button_load.png",
	.info = "Open map (Ctrl+O)",
	.ptr = map_reload},
	{.position = {100, 1080 - 100},
	.file = "assets/button_save.png",
	.info = "Save map (Ctrl+S)",
	.ptr = map_save},
	{.position = {200, 1080 - 100},
	.file = "assets/button_new.png",
	.info = "Create a new map (Ctrl+N)",
	.ptr = map_new},
	{.position = {300, 1080 - 100},
	.file = "assets/button_raise.png",
	.info = "Raise (Ctrl+u)",
	.ptr = button_raise},
	{.position = {400, 1080 - 100},
	.file = "assets/button_lower.png",
	.info = "Lower (Ctrl+D)",
	.ptr = button_lower},
	{.position = {500, 1080 - 100},
	.file = "assets/button_level.png",
	.info = "Level (Ctrl+=)",
	.ptr = button_level},
	{.position = {600, 1080 - 100},
	.file = "assets/button_enlarge.png",
	.info = "Enlarge the map (Ctrl+E)",
	.ptr = enlarge_map},
	{.position = {700, 1080 - 100},
	.file = "assets/button_reduce.png",
	.info = "Reduce the map (Ctrl+r)",
	.ptr = reduce_map}
};

/*
static const param_button_t init_button[] = {
	{.position = {1920 - 100, 0},
	.file = "assets/button_load.png",
	.info = "Open a map",
	.ptr = map_reload},
	{.position = {1920 - 100, 100},
	.file = "assets/button_save.png",
	.info = "Save map",
	.ptr = map_save},
	{.position = {1920 - 100, 200},
	.file = "assets/button_new.png",
	.info = "Create a new map",
	.ptr = map_new},
	{.position = {1920 - 100, 300},
	.file = "assets/button_raise.png",
	.info = "Raise",
	.ptr = button_raise},
	{.position = {1920 - 100, 400},
	.file = "assets/button_lower.png",
	.info = "Lower",
	.ptr = button_lower},
	{.position = {1920 - 100, 500},
	.file = "assets/button_level.png",
	.info = "Level",
	.ptr = button_level},
	{.position = {1920 - 100, 600},
	.file = "assets/button_enlarge.png",
	.info = "Enlarge the map",
	.ptr = enlarge_map},
	{.position = {1920 - 100, 700},
	.file = "assets/button_reduce.png",
	.info = "Reduce the map",
	.ptr = reduce_map}
};
*/


info_t *info_create(char *);
void info_destroy(info_t *);
void info_display(sfRenderWindow *, info_t *);

button_t *button_init(void);
button_t *button_create(button_t *, const param_button_t *);
void button_destroy(button_t *);
sfBool in_bounds(sfVector2i, sfVector2f, sfIntRect);
void button_display(sfRenderWindow *, button_t *, sfEvent);

#endif
