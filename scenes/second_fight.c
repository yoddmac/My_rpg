/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** first_fight
*/

#include "../my_rpg.h"

void open_scene_fight_2(game_t *game)
{
    game->fight->turn_sec += game->time_game->sec;
    damage_zombie(game, game->fight->life_zombie2);
    damage_perso(game);
    draw_texture_fight(game);
    anim_zombie_infight(game);
    draw_texture_buttonfight(game);

    if (game->fight->n == 1) {
        game->fight->rect_perso_fight.top = 0;
        if (game->fight->rect_zombie_fight.top == 0)
            game->fight->rect_zombie_fight.top = 10;
        else
            game->fight->rect_zombie_fight.top = 0;
        if (game->fight->turn_sec >= 2) {
            game->fight->n = 2;
            game->fight->turn_sec = 0;
            game->button_ingame->change = 0;
        }
    }
    fight_2_in_progress(game);
}

void fight_2_in_progress(game_t *game)
{
    if (game->fight->n == 2) {
        game->fight->rect_zombie_fight.top = 0;
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
    fight_2_end(game);
    fight_2_change_scene(game);
}

void fight_2_end(game_t *game)
{
    if (game->button_ingame->change == 1 && game->fight->n == 0) {
        sfRenderWindow_drawSprite(game->window->window,
            game->fight->sprite_perso_fight_fire, NULL);
            game->fight->n = 1;
            game->fight->turn = 1;
        game->fight->life_zombie2 -= rand() % 30;
        sfSound_play(game->sound->sound_zombietakedam);
        damage_zombie(game, game->fight->life_zombie2);
        sfSound_play(game->sound->sound);
        if (game->fight->life_zombie2 <= 0) {
            game->fight->turn_sec = 0;
            game->fight->rect_perso_fight.top = 0;
            game->button_ingame->change = 0;
            game->fight->n = 0;
            game->window->scene = 1;
            game->zombie->alive = 2;
            game->invent->slot_1->quantity += 1;
        }
    }
}

void fight_2_change_scene(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);

    sfSprite_setPosition(game->perso->sprite_perso, pos_s);
    game->perso->perso_max_health = 200;
    sfSprite_setTextureRect(game->fight->sprite_perso_fight,
            game->fight->rect_perso_fight);
}