/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Source file for info struct (mssg displayed when the mouse is over a button.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "buttons.h"

info_t *info_create(char *mssg)
{
	info_t *info = malloc(sizeof(info_t));

	if (info == NULL)
		return (NULL);
	info->font = sfFont_createFromFile("assets/prototype.ttf");
	info->text = sfText_create();
	sfText_setFont(info->text, info->font);
	sfText_setString(info->text, mssg);
	sfText_setColor(info->text, sfRed);
	info->rect = sfText_getLocalBounds(info->text);
	return (info);
}

void info_destroy(info_t *info)
{
	sfFont_destroy(info->font);
	sfText_destroy(info->text);
	free(info);
}

void info_display(sfRenderWindow *window, info_t *info)
{
	sfVector2i pos_int = sfMouse_getPositionRenderWindow(window);
	sfVector2f pos = {pos_int.x, pos_int.y - info->rect.height};

	if (pos.x > WIDTH - info->rect.width)
		pos.x -= info->rect.width;
	if (pos.y < 0)
		pos.y += info->rect.height;
	sfText_setPosition(info->text, pos);
	sfRenderWindow_drawText(window, info->text, 0);
}
