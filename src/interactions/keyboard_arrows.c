/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Functions to move the view of the map using arrows.
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "interactions.h"

int keyboard_up(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	sfView_move(map->view, (sfVector2f) {0, -SPEED_MOVE_VIEW});
	return (0);
}

int keyboard_down(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	sfView_move(map->view, (sfVector2f) {0, SPEED_MOVE_VIEW});
	return (0);
}

int keyboard_left(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	sfView_move(map->view, (sfVector2f) {-SPEED_MOVE_VIEW, 0});
	return (0);
}

int keyboard_right(map_t *map, UNUSED sfEvent *event,
	UNUSED int *mode, UNUSED sfRenderWindow *window)
{
	sfView_move(map->view, (sfVector2f) {SPEED_MOVE_VIEW, 0});
	return (0);
}