/*
** EPITECH PROJECT, 2018
** my_world.h (my_world)
** File description:
** my_world's header
*/

#ifndef MY_WORlD_H
#define MY_WORLD_H

#include "struct.h"
#include "map.h"
#include "buttons.h"

#define UNUSED __attribute__((unused))
#define RTD(a) (a * 180 / M_PI)
#define DTR(a) (a * M_PI / 180)


static int const HEIGHT = 1080;
static int const WIDTH = 1920;
static int const FRAMERATE = 20;

static const char * const ASSETS[] = {
	"assets/button_load.png",
	"assets/button_save.png",
	"assets/button_new.png",
	"assets/button_raise.png",
	"assets/button_lower.png",
	"assets/button_level.png",
	"assets/button_enlarge.png",
	"assets/button_reduce.png",
	"assets/prototype.ttf",
	"assets/LiberationSans-Bold.ttf",
	NULL
};


exit_t parse_arg(char **, char **);
int my_world(const char *);
int game_loop(map_t *);

#endif
