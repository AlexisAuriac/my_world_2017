/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Takes a snapshot of the window.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"
#include "prompt.h"

snapshot_t *snapshot_window(sfRenderWindow *window)
{
	snapshot_t *snapshot = malloc(sizeof(snapshot_t));
	sfColor color = {255, 255, 255, 100};
	sfImage *image = NULL;

	if (snapshot == NULL)
		return (NULL);
	image = sfImage_createFromColor(WIDTH, HEIGHT, color);
	snapshot->texture = sfTexture_createFromImage(image, 0);
	snapshot->sprite = sfSprite_create();
	sfSprite_setTexture(snapshot->sprite, snapshot->texture, 0);
	sfRenderWindow_drawSprite(window, snapshot->sprite, 0);
	sfTexture_updateFromRenderWindow(snapshot->texture, window, 0, 0);
	sfImage_destroy(image);
	sfSprite_setTexture(snapshot->sprite, snapshot->texture, 0);
	return (snapshot);
}

void snapshot_destroy(snapshot_t *snapshot)
{
	sfTexture_destroy(snapshot->texture);
	sfSprite_destroy(snapshot->sprite);
	free(snapshot);
}