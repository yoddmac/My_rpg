/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight_zombie
*/

#include "../../../my_rpg.h"

void create_fight(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);

    if (pos_s.x >= 170 && pos_s.x <= 200 && pos_s.y >= 170 &&
            pos_s.y <= 200 && game->zombie->alive == 0) {
        game->window->scene = 5;
        game->fight->turn = 0;
        sfSprite_setPosition(game->zombie->sprite_zombie,
            (sfVector2f) {3000, 3000});
    }
    fight_2(game);
    if (pos_s.x == 1680  && pos_s.y <= 304 && pos_s.y >= 288
            && game->zombie->alive == 2) {
        game->window->scene = 7;
        sfSprite_setPosition(game->zombie->sprite_bosszombie,
            (sfVector2f){3000, 3000});
    }
}

void fight_2(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);

    if (pos_s.x >= 570 && pos_s.x <= 640 && pos_s.y >= 570 &&
            pos_s.y <= 640 && game->zombie->alive == 1) {
        game->window->scene = 6;
        sfSprite_setPosition(game->zombie->sprite_zombie2,
            (sfVector2f){3000, 3000});
    }
}

void startquest(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);
    if (pos_s.x <= 80 && pos_s.y <= 176 && pos_s.y >= 142
            && game->perso->speak == 0) {
        game->perso->speak = 1;
    }
}

void finishquest(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);
    if (pos_s.x <= 80 && pos_s.y <= 176 && pos_s.y >= 142
            && game->perso->speak == 1) {
        game->perso->speak = 2;
        game->invent->slot_2->quantity = 0;
    }
}