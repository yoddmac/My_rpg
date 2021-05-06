/*
** EPITECH PROJECT, 2020
** my_strtok.c
** File description:
** my_strtok
*/

#include <stdlib.h>
#include "../../my_rpg.h"

char *my_strchr(const char *str, char c)
{
    while (*str != c)
        if (!*str++)
            return NULL;
    return (str);
}

int my_strspn(const char *str, const char *accept)
{
    int num;
    for (num = 0; *str && my_strchr(accept, *str++); num++) {
    }
    return (num);
}

int my_strcspn(const char *str, const char *reject)
{
    int num = 0;
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (my_strchr(reject, str[i]))
            return num;
        else {
            num++;
        }
    return num;
}

char *my_strtok(char *str, const char *sep)
{
    static char *save = NULL;

    if (str != NULL)
        save = str;
    else if (save == NULL)
        return NULL;
    str = save + my_strspn(save, sep);
    save = str + my_strcspn(str, sep);
    if (save == str)
        return NULL;
    save = *save ? *save = 0, save + 1 : 0;
    return (str);
}
