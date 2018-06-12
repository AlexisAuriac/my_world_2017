/*
** EPITECH PROJECT, 2018
** init_interactions (my_world)
** File description:
** initialize user interactions handling
*/

#include "interactions.h"

void init_keyboard_interactions(interactions_t *interactions)
{
	for (int i = 0; i < sfKeyCount; ++i)
		interactions->keyboard_interaction[i] = NULL;
	interactions->keyboard_interaction[sfKeyLeft] = keyboard_left;
	interactions->keyboard_interaction[sfKeyRight] = keyboard_right;
	interactions->keyboard_interaction[sfKeyDown] = keyboard_down;
	interactions->keyboard_interaction[sfKeyUp] = keyboard_up;
	interactions->keyboard_interaction[sfKeyEscape] = keyboard_escape;
	interactions->keyboard_interaction[sfKeyPageUp] = keyboard_page_up;
	interactions->keyboard_interaction[sfKeyPageDown] = keyboard_page_down;
	interactions->keyboard_interaction[sfKeyO] = keyboard_o;
	interactions->keyboard_interaction[sfKeyS] = keyboard_s;
	interactions->keyboard_interaction[sfKeyN] = keyboard_n;
	interactions->keyboard_interaction[sfKeyE] = keyboard_e;
	interactions->keyboard_interaction[sfKeyR] = keyboard_r;
	interactions->keyboard_interaction[sfKeyEqual] = keyboard_equal;
	interactions->keyboard_interaction[sfKeyU] = keyboard_u;
	interactions->keyboard_interaction[sfKeyD] = keyboard_d;
}

void init_interactions(interactions_t *interactions)
{
	init_keyboard_interactions(interactions);
	interactions->buttons = button_init();
}
