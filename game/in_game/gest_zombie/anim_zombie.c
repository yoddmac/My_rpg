/*
** EPITECH PROJECT, 2020
** mouve_zombie
** File description:
** mouve_zombie
*/

#include "../../../my_rpg.h"

void init_rect_zombie(game_t *game)
{
    game->zombie->rect_zombie.width = 40;
    game->zombie->rect_zombie.height = 72;
}

void init_rect_zombie2(game_t *game)
{
    game->zombie->rect_zombie2.width = 40;
    game->zombie->rect_zombie2.height = 72;
}

void init_rect_zombie_infight(game_t *game)
{
    game->fight->rect_zombie_fight.width = 64;
    game->fight->rect_zombie_fight.height = 106;
}

void anim_zombie_infight(game_t *game)
{
    game->fight->sec += game->time_game->sec;

    if (game->fight->sec >= 0.7) {
        if (game->fight->rect_zombie_fight.left == 0)
            game->fight->rect_zombie_fight.left = 64;
        else
            game->fight->rect_zombie_fight.left = 0;
        game->fight->sec = 0;
    }
    sfSprite_setTextureRect(game->fight->sprite_zombie_fight,
        game->fight->rect_zombie_fight);
}

void anim_zombie(game_t *game)
{
    init_rect_zombie(game);
    init_rect_zombie2(game);
    game->zombie->time += game->time_game->sec;

    if (game->zombie->time >= 0.07) {
        game->zombie->rect_zombie.left += 40;
        game->zombie->rect_zombie2.left += 40;
        if (game->zombie->rect_zombie.left >= 320)
            game->zombie->rect_zombie.left = 0;
        if (game->zombie->rect_zombie2.left >= 320)
            game->zombie->rect_zombie2.left = 0;
        sfSprite_setTextureRect(game->zombie->sprite_zombie,
            game->zombie->rect_zombie);
        sfSprite_setTextureRect(game->zombie->sprite_zombie2,
                                game->zombie->rect_zombie2);
        game->zombie->time = 0;
    }
}