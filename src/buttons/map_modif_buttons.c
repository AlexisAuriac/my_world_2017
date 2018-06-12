/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Changes the function pointer to change the map.
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "interactions.h"
#include "map.h"

void button_raise(map_t *map, UNUSED sfRenderWindow *window)
{
	map->modif = interactions_map_raise;
}

void button_lower(map_t *map, UNUSED sfRenderWindow *window)
{
	map->modif = interactions_map_lower;
}

void button_level(map_t *map, UNUSED sfRenderWindow *window)
{
	map->modif = interactions_map_level;
}