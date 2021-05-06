/*
** EPITECH PROJECT, 2020
** scene
** File description:
** scene
*/

#include "../my_rpg.h"

void open_scene_game(game_t *game)
{
    if (game->window->scene == 0)
        draw_texture_menu(game);
    if (game->window->scene == 1) {
        sfRenderWindow_drawVertexArray(game->window->window,
            game->vertex_map->map_array, &game->vertex_map->state);
        sfRenderWindow_drawVertexArray(game->window->window,
            game->vertex_map->map_props, &game->vertex_map->state);
        draw_texture_game(game);
        sfRenderWindow_drawSprite(game->window->window,
            game->rain->sprite, NULL);
        inventory_render(game);
        if (game->menu->end_story == 0) {
            draw_story_game(game);
            game->window->scene = 1;
        }
    }
    if (game->window->scene == 3)
        sfRenderWindow_drawSprite(game->window->window, game->menu->spritehowtoplay, NULL);
    gestion_scenes_fight(game);
}

void gestion_scenes_fight(game_t *game)
{
    if (game->window->scene == 5)
        open_scene_fight(game);
    if (game->window->scene == 6)
        open_scene_fight_2(game);
    if (game->window->scene == 7)
        open_scene_fight_boss(game);
}

void open_scene_in_game(game_t *game)
{
    if (game->pause->scene == 1)
        draw_texture_pause(game);
    if (game->pause->scene == 2)
        game->window->scene = 1;
}