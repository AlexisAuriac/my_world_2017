/*
** EPITECH PROJECT, 2018
** my_world_interactions.h
** File description:
** user's interactions header
*/

#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct.h"
#include "map.h"
#include "buttons.h"

typedef struct interactions {
	int (*keyboard_interaction[sfKeyCount])
	(map_t *, sfEvent *, int *, sfRenderWindow *);
	button_t *buttons;
}interactions_t;


int interactions_closed
(map_t *, sfEvent *, interactions_t *, sfRenderWindow *);
int interactions_keypressed
(map_t *, sfEvent *, interactions_t *, sfRenderWindow *);
int interaction_mouse_released
(map_t *, sfEvent *, interactions_t *, sfRenderWindow *);

static int (*const type_interaction[sfEvtCount])
(map_t *, sfEvent *, interactions_t *, sfRenderWindow *window) = {
	[sfEvtClosed] = interactions_closed,
	[sfEvtKeyPressed] = interactions_keypressed,
	[sfEvtMouseButtonReleased] = interaction_mouse_released,
};

static const int SPEED_MOVE_VIEW = 15;


void init_interactions(interactions_t *);
void interactions_click_map(map_t *, sfEvent *, sfRenderWindow *);
void interactions_map_raise(point_t *);
void interactions_map_lower(point_t *);
void interactions_map_level(point_t *);

int keyboard_up(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_down(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_left(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_right(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_escape(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_page_up(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_page_down(map_t *, sfEvent *, int *, sfRenderWindow *);
void interactions_move_view(sfView *, sfRenderWindow *);
int keyboard_o(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_s(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_n(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_e(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_r(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_equal(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_u(map_t *, sfEvent *, int *, sfRenderWindow *);
int keyboard_d(map_t *, sfEvent *, int *, sfRenderWindow *);

#endif
