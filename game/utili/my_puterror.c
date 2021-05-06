/*
** EPITECH PROJECT, 2020
** my_puterror.c
** File description:
** my_puterror
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        my_putchar(str[i]);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        my_putchar_error(str[i]);
}