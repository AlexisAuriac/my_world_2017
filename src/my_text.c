/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Source file for the text struct who can be used to easily draw text.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "my_text.h"

text_t *text_create(const char *str, const char *font_name)
{
	text_t *text = malloc(sizeof(text_t));

	if (text == NULL)
		return (NULL);
	*text = DEFAULT_TEXT;
	text->str = str;
	text->font = sfFont_createFromFile(font_name);
	text->text = sfText_create();
	sfText_setString(text->text, text->str);
	sfText_setFont(text->text, text->font);
	sfText_setCharacterSize(text->text, text->size);
	return (text);
}

void text_destroy(text_t *text)
{
	sfFont_destroy(text->font);
	sfText_destroy(text->text);
	free(text);
}

void alert(sfRenderWindow *window, const char *str, sfVector2f offset)
{
	text_t *text = text_create(str, "assets/LiberationSans-Bold.ttf");
	sfFloatRect rect;

	if (text == NULL)
		return;
	rect = sfText_getLocalBounds(text->text);
	text->pos.x = WIDTH / 2 - rect.width / 2 + offset.x;
	text->pos.y = HEIGHT / 2 - rect.height / 2 + offset.y;
	sfText_setPosition(text->text, text->pos);
	sfRenderWindow_drawText(window, text->text, 0);
	text_destroy(text);
}