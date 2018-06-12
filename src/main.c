/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "map.h"
#include "my_world.h"

int main(int ac, UNUSED char **av, char **envp)
{
	switch (parse_arg(av, envp)) {
	case FAILURE :
		return (84);
	case SUCCESS :
		return (0);
	default:
		break;
	}
	my_world((ac == 1) ? NULL : av[1]);
	return (0);
}
