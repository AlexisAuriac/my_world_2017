/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Parses arguments for error handling and options.
*/

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_world.h"
#include "my_text.h"

exit_t error_arg(char **envp)
{
	bool display = false;

	for (int i = 0 ; envp[i] ; ++i) {
		if (my_strncmp("DISPLAY=", envp[i], 8) == 0) {
			display = true;
			break;
		}
	}
	if (!display) {
		my_puterr("Aborting: DISPLAY variable not set\n");
		return (FAILURE);
	}
	return (CONTINUE);
}

void help(void)
{
	my_putstr(USAGE);
}

exit_t option(char *argv)
{
	if (argv[0] != '-')
		return (CONTINUE);
	if (my_strcmp(argv, "-h") == 0) {
		help();
		return (SUCCESS);
	}
	my_putstr("Unknown option: ");
	my_putstr(argv);
	my_putchar('\n');
	return (FAILURE);
}

exit_t error_files(const char *file)
{
	int fd = -1;
	exit_t error = CONTINUE;
	int len = my_strlen(file);

	if (file != NULL && (len < 7 || my_strcmp(file + len - 6, ".world"))) {
		my_putstr(file);
		my_putstr(": Invalid file name, ");
		my_putstr("you must give a file with the extension .world\n");
		return (FAILURE);
	}
	for (int i = 0 ; ASSETS[i] ; ++i) {
		fd = open(ASSETS[i], R_OK);
		if (fd == -1) {
			my_puterr(ASSETS[i]);
			my_puterr(" is missing\n");
			error = FAILURE;
		}
		else
			close(fd);
	}
	return (error);
}

exit_t parse_arg(char **av, char **envp)
{
	exit_t error = CONTINUE;

	error = error_arg(envp);
	if (error)
		return (error);
	if (av[1] != NULL) {
		error = option(av[1]);
		if (error)
			return (error);
		error = error_files(av[1]);
	}
	return (error);
}
