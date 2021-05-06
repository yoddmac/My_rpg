/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my_rpg.h"

void game_create(game_t *game)
{
        game->window = malloc(sizeof(window_t));
        game->menu = malloc(sizeof(menu_t));
        game->rain = malloc(sizeof(rain_t));
        game->perso = malloc(sizeof(perso_t));
        game->zombie = malloc(sizeof(zombie_t));
        game->time_game = malloc(sizeof(time_game_t));
        game->pause = malloc(sizeof(pause_t));
        game->fight = malloc(sizeof(fight_t));
        game->sound = malloc(sizeof(sound_t));
        game->button_ingame = malloc(sizeof(button_ingame_t));
        game->score = malloc(sizeof(score_t));
        game->invent = malloc(sizeof(invent_t));
        game->invent->slot_1 = malloc(sizeof(slot_t));
        game->invent->slot_2 = malloc(sizeof(slot_t));
        game->time_game->clock = sfClock_create();
        create_window(game);
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    game->restart = 1;
    if (ac == 1) {
        while(game->restart == 1) {
            game->restart = 0;
            game_create(game);
        }
    }
    free(game);
    return (0);
}