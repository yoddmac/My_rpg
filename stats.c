/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stats
*/

#include "my_rpg.h"

void stats_life(game_t *game)
{
    char *perso = malloc(sizeof(char *) *100);
    char *health = malloc(sizeof(char *) * 100 );
    perso = itoa(game->perso->perso_life, perso);
    health = itoa(game->perso->perso_max_health, health);
    sfText_setFont(game->perso->text_life, game->score->font);
    sfText_setFont(game->perso->text_slach, game->score->font);
    sfText_setFont(game->perso->text_life_max, game->score->font);
    sfText_setString(game->perso->text_life, perso);
    sfText_setString(game->perso->text_life_max, "/");
    sfText_setString(game->perso->text_slach, health);
    sfText_setCharacterSize(game->perso->text_life, 50);
    sfText_setCharacterSize(game->perso->text_slach, 50);
    sfText_setCharacterSize(game->perso->text_life_max, 50);
    sfText_setColor(game->perso->text_life, sfRed);
    sfText_setColor(game->perso->text_slach, sfRed);
    sfText_setColor(game->perso->text_life_max, sfRed);
    sfMouse_getPositionRenderWindow(game->window->window);
    sfText_setPosition(game->perso->text_life, (sfVector2f) {1700, 5});
    sfText_setPosition(game->perso->text_slach, (sfVector2f) {1830, 5});
    sfText_setPosition(game->perso->text_life_max, (sfVector2f) {1790, 5});
}