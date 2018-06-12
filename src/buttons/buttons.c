/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Handles buttons.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "buttons.h"

button_t *button_init(void)
{
	button_t *first = NULL;

	for (int i = 0 ; i < NB_BUTTON ; ++i)
		first = button_create(first, &init_button[i]);
	return (first);
}

button_t *button_create(button_t *first, const param_button_t *init)
{
	button_t *button = malloc(sizeof(button_t));

	if (button == NULL)
		return (NULL);
	button->texture = sfTexture_createFromFile(init->file, 0);
	button->sprite = sfSprite_create();
	sfSprite_setTexture(button->sprite, button->texture, 0);
	button->pos = init->position;
	button->ptr = init->ptr;
	sfSprite_setPosition(button->sprite, button->pos);
	button->rect = (sfIntRect) {0, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
	button->state = IDLE;
	button->info = info_create(init->info);
	button->next = first;
	return (button);
}
void button_destroy(button_t *first)
{
	button_t *to_delete = NULL;

	while (first != NULL) {
		to_delete = first;
		first = first->next;
		sfTexture_destroy(to_delete->texture);
		sfSprite_destroy(to_delete->sprite);
		info_destroy(to_delete->info);
		free(to_delete);
	}
}

sfBool in_bounds(sfVector2i pos, sfVector2f pos_spr, sfIntRect rect)
{
	if (pos.x < pos_spr.x || pos.x > pos_spr.x + rect.width)
		return (sfFalse);
	else if (pos.y < pos_spr.y || pos.y > pos_spr.y + rect.height)
		return (sfFalse);
	return (sfTrue);
}

void button_display(sfRenderWindow *window, button_t *first, sfEvent event)
{
	sfVector2i pos_ms = sfMouse_getPositionRenderWindow(window);

	while (first != NULL) {
		if (in_bounds(pos_ms, first->pos, first->rect)) {
			if (sfMouse_isButtonPressed(event.mouseButton.button))
				first->state = CLICKED;
			else
				first->state = HOVER;
		}
		else
			first->state = IDLE;
		first->rect.left = first->state * BUTTON_WIDTH;
		sfSprite_setTextureRect(first->sprite, first->rect);
		sfRenderWindow_drawSprite(window, first->sprite, 0);
		if (first->state != IDLE)
			info_display(window, first->info);
		first = first->next;
	}
}
