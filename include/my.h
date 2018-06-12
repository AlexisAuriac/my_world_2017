/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** .h library for my
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdbool.h>

#define READ_SIZE 10

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
void *my_malloc(int);
char *my_strcpy(char *, char const *);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
void *my_memset(void *, char, size_t);
void *my_realloc(void *, int const);
int my_strtol(char **);
char *my_append(char *, char const *);
char *my_read_all(int);
int my_strcmp(const char *, const char *);
int my_strncmp(char const *, char const *, int);
void my_puterr(const char *);
char *get_next_line(int);
bool in_str(char const, char const *);
int my_index(const char, const char *);
int my_rindex(const char, const char *);

#endif
