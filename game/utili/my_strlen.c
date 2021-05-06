/*
** EPITECH PROJECT, 2020
** my_puterror.c
** File description:
** my_puterror
*/

#include "../../my_rpg.h"

int my_strlen (char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}