/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite_game_2
*/

#include "../../my_rpg.h"

void init_rain_anim(game_t *game)
{
    game->rain->rect.height = 1080;
    game->rain->rect.width = 1920;
    game->rain->rect.left = 0;
    game->rain->rect.top = 0;
}

void init_sprite_game(game_t *game)
{
    create_sprite_game(game);
    create_texture_game(game);
    set_texture_game(game);
    init_rain_anim(game);
}

void animation(game_t *game)
{
    game->rain->sec += game->time_game->sec;
    if (game->rain->sec > 0.05) {
        game->rain->rect.left += 1080;
        if (game->rain->rect.left == 3240)
            game->rain->rect.left = 0;
        game->rain->sec = 0;
    }
    sfSprite_setTextureRect (game->rain->sprite, game->rain->rect);
}