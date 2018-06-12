/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Header file for the text structure.
*/

#ifndef MY_TEXT_H
#define MY_TEXT_H

typedef struct text {
	const char *str;
	int size;
	sfColor color;
	sfVector2f pos;
	sfFont *font;
	sfText *text;
}text_t;

static const text_t DEFAULT_TEXT = {
	.str = "",
	.size = 50,
	.color = {255, 255, 255, 255},
	.pos = {0},
	.font = NULL,
	.text = NULL
};

static char const USAGE[] = "Usage: ./my_world [option][map]\n"
	"3D map editor\n"
	"\n"
	"Option(s):\n"
	"\t-h                 Display this help\n"
	"\n"
	"Interaction(s):\n"
	"\tCtrl + o           load an existing map\n"
	"\tCtrl + s           save the current map\n"
	"\tCtrl + n           create a new map\n"
	"\tCtrl + e           enlarge by one in the two dimensions the map\n"
	"\tCtrl + r           reduce bu one in the two dimensions the map\n"
	"\tCtrl + =           switch to null level mod\n"
	"\tCtrl + u           switch to up level mod\n"
	"\tCtrl + d           switch to down level mod\n"
	"\tEchap              quit the game\n"
	"\tArrows             move around the map\n"
	"\n"
	"N.B. : You can also use buttons displayed on the screen\n";

text_t *text_create(const char *str, const char *font_name);
void text_destroy(text_t *text);
void alert(sfRenderWindow *window, const char *str, sfVector2f offset);

#endif
