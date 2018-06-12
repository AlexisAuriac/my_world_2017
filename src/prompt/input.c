/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Definitions of the functions relative to the input structure.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "prompt.h"

input_t *input_create(void)
{
	input_t *input = malloc(sizeof(input_t));

	if (input == NULL)
		return (NULL);
	for (int i = 0 ; i < 4097 ; ++i)
		input->str[i] = '\0';
	input->pos.x = 0;
	input->pos.y = HEIGHT / 2 - INPUT_SIZE / 2;
	input->font = sfFont_createFromFile(INPUT_FONT);
	input->text = sfText_create();
	sfText_setFont(input->text, input->font);
	sfText_setColor(input->text, INPUT_COLOR);
	sfText_setCharacterSize(input->text, INPUT_SIZE);
	return (input);
}

void input_destroy(input_t *input)
{
	sfFont_destroy(input->font);
	sfText_destroy(input->text);
	free(input);
}

void input_display(sfRenderWindow *window, input_t *input)
{
	sfFloatRect rect = sfText_getLocalBounds(input->text);

	input->pos.x = WIDTH / 2 - rect.width / 2;
	sfText_setPosition(input->text, input->pos);
	sfText_setString(input->text, input->str);
	sfRenderWindow_drawText(window, input->text, 0);
}