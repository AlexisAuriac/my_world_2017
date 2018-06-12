/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Headers for the graphical prompt.
*/

#ifndef PROMPT_H
#define PROMPT_H

#include <SFML/Graphics.h>

typedef struct snapshot {
	sfTexture *texture;
	sfSprite *sprite;
}snapshot_t;

typedef struct input {
	sfFont *font;
	sfText *text;
	char str[4097];
	sfVector2f pos;
}input_t;

typedef struct prompt {
	input_t *input;
	snapshot_t *snapshot;
	char *str;
}prompt_t;


static const char INPUT_FONT[] = "assets/LiberationSans-Bold.ttf";
static const sfColor INPUT_COLOR = {255, 255, 255, 255};
static const int INPUT_SIZE = 42;

static const char PROMPT_TEXT[] = "Enter text";


snapshot_t *snapshot_window(sfRenderWindow *);
void snapshot_destroy(snapshot_t *);

input_t *input_create(void);
void input_destroy(input_t *);
void input_display(sfRenderWindow *, input_t *);

exit_t event_prompt(sfRenderWindow *, char *);
char *graph_prompt(sfRenderWindow *);

#endif
