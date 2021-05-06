/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy
*/

#include "my_rpg.h"

void destroy_menu(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    sfSprite_destroy(game->menu->sprite_fond);
    sfSprite_destroy(game->menu->quit_sprite);
    sfSprite_destroy(game->menu->start_sprite);
    sfSprite_destroy(game->menu->go_sprite);
    sfSprite_destroy(game->menu->option_sprite);
    sfSprite_destroy(game->menu->resume_sprite);
    sfTexture_destroy(game->menu->texture_fond);
    sfTexture_destroy(game->menu->start_texture);
    sfTexture_destroy(game->menu->start2_texture);
    sfTexture_destroy(game->menu->option2_texture);
    sfTexture_destroy(game->menu->option_texture);
    sfTexture_destroy(game->menu->quit_texture);
    sfTexture_destroy(game->menu->quit2_texture);
    sfTexture_destroy(game->menu->resume_texture);
    sfTexture_destroy(game->menu->go_texture);
    free(game->menu);
}

void destroy_vertex_map(game_t *game)
{
    sfVertexArray_destroy(game->vertex_map->map_array);
    sfVertexArray_destroy(game->vertex_map->map_props);
    sfTexture_destroy(game->vertex_map->tiles_text);
    free(game->vertex_map);
}

void destroy_perso(game_t *game)
{
    sfSprite_destroy(game->perso->spritepnj_quete);
    sfTexture_destroy(game->perso->texturepnj_quete);
    sfSprite_destroy(game->perso->sprite_speakpnj);
    sfTexture_destroy(game->perso->texture_speakpnj);
    sfSprite_destroy(game->perso->sprite_perso);
    sfSprite_destroy(game->perso->texture_perso);
    sfText_destroy(game->perso->text_life);
    sfText_destroy(game->perso->text_slach);
    sfText_destroy(game->perso->text_life_max);
    free(game->perso);
}

void destroy_zombie(game_t *game)
{
    sfSprite_destroy(game->zombie->sprite_zombie);
    sfTexture_destroy(game->zombie->texture_zombie);
    sfSprite_destroy(game->zombie->sprite_zombie2);
    sfTexture_destroy(game->zombie->texture_zombie2);
    sfSprite_destroy(game->zombie->sprite_bosszombie);
    sfTexture_destroy(game->zombie->texture_bosszombie);
    free(game->zombie);
    sfClock_destroy(game->time_game->clock);
    free(game->time_game);
}

void destroy_time(game_t *game)
{
    sfSprite_destroy(game->pause->sprite_pause_font);
    sfTexture_destroy(game->pause->texture_pause_font);
    sfSprite_destroy(game->pause->resume_sprite);
    sfTexture_destroy(game->pause->resume_texture);
    sfSprite_destroy(game->pause->menu_sprite);
    sfTexture_destroy(game->pause->menu_texture);
    sfSprite_destroy(game->pause->exit_sprite);
    sfTexture_destroy(game->pause->exit_texture);
    free(game->pause);
}

void destroy_all(game_t *game)
{
    destroy_menu(game);
    destroy_vertex_map(game);
    destroy_perso(game);
    destroy_zombie(game);
    destroy_time(game);
    destroy_fight(game);
    destroy_sound(game);
    destroy_score(game);
    destroy_slot(game);
    destroy_rain(game);
}