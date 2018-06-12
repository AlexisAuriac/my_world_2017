/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Displays a prompt in the window.
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "my_text.h"
#include "prompt.h"

prompt_t *prompt_create(sfRenderWindow *window)
{
	prompt_t *prompt = malloc(sizeof(prompt_t));

	if (prompt == NULL)
		return (NULL);
	alert(window, "Enter a map:", (sfVector2f) {0, -60});
	prompt->input = input_create();
	if (prompt->input == NULL) {
		free(prompt);
		return (NULL);
	}
	prompt->snapshot = snapshot_window(window);
	if (prompt->snapshot == NULL) {
		free(prompt->input);
		free(prompt);
		return (NULL);
	}
	return (prompt);
}

void prompt_destroy(prompt_t *prompt)
{
	input_destroy(prompt->input);
	snapshot_destroy(prompt->snapshot);
	free(prompt);
}

void write_prompt(sfUint32 code, char *input)
{
	int len = my_strlen(input);

	if (code < 128 && code > 31 && len < 4096)
		input[len] = code;
	else if (code == 8 && len > 0)
		input[len - 1] = '\0';
}

exit_t event_prompt(sfRenderWindow *window, char *input)
{
	sfEvent event = {0};

	while (sfRenderWindow_pollEvent(window, &event)) {
		switch (event.type) {
		case sfEvtClosed :
			sfRenderWindow_close(window);
			break;
		case sfEvtKeyPressed :
			if (event.key.code == sfKeyEscape)
				return (FAILURE);
			else if (event.key.code == sfKeyReturn)
				return (SUCCESS);
			break;
		case sfEvtTextEntered :
			write_prompt(event.key.code, input);
			break;
		default :
			break;
		}
	}
	return (CONTINUE);
}

char *graph_prompt(sfRenderWindow *window)
{
	exit_t quit = CONTINUE;
	prompt_t *prompt = prompt_create(window);
	char *str = NULL;

	while (quit == CONTINUE && sfRenderWindow_isOpen(window)) {
		sfRenderWindow_drawSprite(window, prompt->snapshot->sprite, 0);
		input_display(window, prompt->input);
		sfRenderWindow_display(window);
		quit = event_prompt(window, prompt->input->str);
		if (quit != CONTINUE)
			break;
	}
	str = (quit == SUCCESS) ? my_strdup(prompt->input->str) : NULL;
	prompt_destroy(prompt);
	if (quit == FAILURE)
		return (NULL);
	return (str);
}
