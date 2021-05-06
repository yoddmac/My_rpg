/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_boss
*/

#include "../my_rpg.h"

void open_scene_fight_boss(game_t *game)
{
    draw_texture_fight_boss(game);
    draw_texture_buttonfight(game);
    damage_zombie(game, game->fight->life_boss);
    damage_perso(game);
    game->fight->turn_sec += game->time_game->sec;

    if (game->fight->n == 1) {
        game->fight->rect_perso_fight.top = 0;
        if (game->fight->rect_boss_fight.top == 0)
            game->fight->rect_boss_fight.top = 10;
        else
            game->fight->rect_boss_fight.top = 0;
        if (game->fight->turn_sec >= 2) {
            game->fight->n = 2;
            game->fight->turn_sec = 0;
            game->button_ingame->change = 0;
        }
    }
    fight_boss_in_progress(game);
}

void fight_boss_in_progress(game_t *game)
{
    if (game->fight->n == 2) {
        game->fight->rect_boss_fight.top = 0;
        if (game->fight->rect_perso_fight.top == 0)
            game->fight->rect_perso_fight.top = 10;
        else
            game->fight->rect_perso_fight.top = 0;
        if (game->fight->turn_sec >= 2) {
            game->fight->n = 0;
            game->fight->turn_sec = 0;
            game->button_ingame->change = 0;
            game->perso->perso_life -=  rand () % 20;
            sfSound_play(game->sound->sound_persotakedam);
            damage_perso(game);
        }
    }
    fight_boss_end(game);
    fight_boss_change_scene(game);
}

void fight_boss_end(game_t *game)
{
    if (game->button_ingame->change == 1 && game->fight->n == 0) {
        sfRenderWindow_drawSprite(game->window->window,
            game->fight->sprite_perso_fight_fire, NULL);
            game->fight->n = 1;
            game->fight->turn = 1;
        sfSound_play(game->sound->sound_zombietakedam);
        game->fight->life_boss -= rand() % 40;
        damage_zombie(game, game->fight->life_boss);
        sfSound_play(game->sound->sound);
        if (game->fight->life_boss <= 0) {
            game->fight->turn_sec = 0;
            game->fight->rect_perso_fight.top = 0;
            game->button_ingame->change = 0;
            game->fight->n = 0;
            game->window->scene = 1;
            game->zombie->alive = 3;
            game->invent->slot_1->quantity += 4;
            game->invent->slot_2->quantity = 1;
        }
    }
}

void fight_boss_change_scene(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);

    sfSprite_setPosition(game->perso->sprite_perso, pos_s);
    game->perso->perso_max_health = 400;
    sfSprite_setTextureRect(game->fight->sprite_perso_fight,
        game->fight->rect_perso_fight);
    sfSprite_setTextureRect(game->fight->sprite_boss_fight,
        game->fight->rect_boss_fight);
}