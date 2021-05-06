/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** analyse_events
*/

#include "../../my_rpg.h"

void analyse_events(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->window);
    if (game->window->event.type == sfEvtKeyPressed) {
        key_moves(game);
        if (game->window->event.key.code == sfKeyE) {
            if (game->perso->speak == 0)
                startquest(game);
            if (game->perso->speak == 1 && game->invent->slot_2->quantity == 1)
                finishquest(game);
            }
        if (game->window->event.key.code == sfKeyP) {
            if (game->pause->scene == 1)
                game->pause->scene = 0;
            else
                game->pause->scene = 1;
        }
    }
}

void key_moves(game_t *game)
{
    if (game->window->event.key.code == sfKeyUp)
            mouve_perso_up(game);
        if (game->window->event.key.code == sfKeyDown)
            mouve_perso_down(game);
        if (game->window->event.key.code == sfKeyLeft)
            mouve_perso_left(game);
        if (game->window->event.key.code == sfKeyRight)
            mouve_perso_right(game);
}