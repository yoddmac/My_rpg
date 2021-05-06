/*
** EPITECH PROJECT, 2020
** destroy2
** File description:
** destroy2
*/

#include "my_rpg.h"

void destroy_fight(game_t *game)
{
    sfSprite_destroy(game->fight->house_sprite);
    sfTexture_destroy(game->fight->house_texture);
    sfSprite_destroy(game->fight->sprite_perso_fight);
    sfTexture_destroy(game->fight->texture_perso_fight);
    sfSprite_destroy(game->fight->sprite_perso_fight_fire);
    sfTexture_destroy(game->fight->texture_perso_fight_fire);
    sfSprite_destroy(game->fight->sprite_zombie_fight);
    sfTexture_destroy(game->fight->texture_zombie_fight);
    sfSprite_destroy(game->fight->sprite_boss_fight);
    sfTexture_destroy(game->fight->texture_boss_fight);
    sfSprite_destroy(game->fight->sprite_cemetery);
    sfTexture_destroy(game->fight->texture_cemetery);
    free(game->fight);
}

void destroy_sound(game_t *game)
{
    sfSoundBuffer_destroy(game->sound->buffer);
    sfSound_destroy(game->sound->sound);
    sfSoundBuffer_destroy(game->sound->buffer_typewriter);
    sfSound_destroy(game->sound->sound_typewriter);
    sfMusic_destroy(game->sound->music_ingame);
    sfMusic_destroy(game->sound->music_menu);
    sfSoundBuffer_destroy(game->sound->buffer_heal);
    sfSound_destroy(game->sound->sound_heal);
    sfSoundBuffer_destroy(game->sound->buffer_click);
    sfSound_destroy(game->sound->sound_click);
    sfSoundBuffer_destroy(game->sound->buffer_zombietakedam);
    sfSoundBuffer_destroy(game->sound->buffer_persotakedam);
    sfSound_destroy(game->sound->sound_persotakedam);
    free(game->sound);
    sfSprite_destroy(game->button_ingame->sprite_attack);
    sfTexture_destroy(game->button_ingame->texture_attack);
    free(game->button_ingame);
}

void destroy_score(game_t *game)
{
    sfTexture_destroy(game->score->score);
    sfText_destroy(game->score->text_perso);
    sfText_destroy(game->score->text_zombie);
    sfFont_destroy(game->score->font);
    sfClock_destroy(game->score->clock);
    free(game->score);
}

void destroy_slot(game_t *game)
{
    sfSprite_destroy(game->invent->slot_1->sprite);
    sfTexture_destroy(game->invent->slot_1->texture);
    sfSprite_destroy(game->invent->slot_2->sprite);
    sfTexture_destroy(game->invent->slot_2->texture);
    free(game->invent->slot_1);
    free(game->invent->slot_2);
}

void destroy_rain(game_t *game)
{
    sfSprite_destroy(game->rain->sprite);
    sfTexture_destroy(game->rain->texture);
    free(game->rain);
}