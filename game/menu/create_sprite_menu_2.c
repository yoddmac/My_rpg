/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite_menu_2
*/

#include "../../my_rpg.h"

void draw_texture_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->sprite_fond, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->start_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->option_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->quit_sprite, NULL);
}

void draw_story_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->resume_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->menu->go_sprite, NULL);
}

void init_sprite_menu(game_t *game)
{
    create_sprite_menu(game);
    create_texture_menu(game);
    set_texture_menu(game);
}