/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attack
*/

#include "my_rpg.h"

char *itoa(int i, char b[])
{
    char const digit[] = "0123456789";
    char *p = b;
    if (i < 0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do {
        ++p;
        shifter = shifter/10;
    } while (shifter);
    *p = '\0';
    do {
        *--p = digit[i%10];
        i = i/10;
    } while (i);
    return b;
}

char *rev_nbr(char *str)
{
    char *result = malloc(sizeof(char) * 4);
    int k = 0;

    for (int i = 3; i >= 0; i--, k++) {
        result[k] = str[i];
    }
    result[5] = '\0';
    return (result);
}

char *my_get_nbr(int nb)
{
    int n = 1;
    int temp = nb;
    char res = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * 4);

    while (nb / n > 9) {
        n *= 10;
    }
    for (; i < 4; i++) {
        if (n > 0) {
            res = temp / n;
            temp %= n;
            result[i] = (res + '0');
            n /= 10;
        } else {
            result[i] = '0';
        }
    }
    result = rev_nbr(result);
    return (result);
}

void damage_zombie(game_t *game, int zombie)
{
    char *value = malloc(sizeof(char *) *100);

    value = itoa(zombie, value);
    sfText_setFont(game->score->text_zombie, game->score->font);
    sfText_setString(game->score->text_zombie, value);
    sfText_setCharacterSize(game->score->text_zombie, 50);
    sfText_setColor(game->score->text_zombie, sfRed);
    sfMouse_getPositionRenderWindow(game->window->window);
    sfText_setPosition(game->score->text_zombie, (sfVector2f) {700, 450});
    sfVector2f textpos = sfText_getPosition(game->score->text_zombie);
}

void damage_perso(game_t *game)
{
    char *p_value = malloc(sizeof(char *) * 100);

    p_value = itoa(game->perso->perso_life, p_value);
    sfText_setFont(game->score->text_perso, game->score->font);
    sfText_setString(game->score->text_perso, p_value);
    sfText_setCharacterSize(game->score->text_perso, 50);
    sfText_setColor(game->score->text_perso, sfBlue);
    sfMouse_getPositionRenderWindow(game->window->window);
    sfText_setPosition(game->score->text_perso, (sfVector2f) {420, 500});
}