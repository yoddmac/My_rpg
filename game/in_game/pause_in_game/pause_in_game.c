/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause
*/

#include "../../../my_rpg.h"

void create_sprite_pause(game_t *game)
{
    game->pause->sprite_pause_font = sfSprite_create();
    game->pause->resume_sprite = sfSprite_create();
    game->pause->menu_sprite = sfSprite_create();
    game->pause->exit_sprite = sfSprite_create();
}

void create_texture_pause(game_t *game)
{
    game->pause->texture_pause_font = sfTexture_createFromFile(
        "./game/in_game/pause_in_game/png/pause_fond.png", NULL);
    game->pause->resume_texture = sfTexture_createFromFile(
        "./game/in_game/pause_in_game/png/resume.png", NULL);
    game->pause->menu_texture = sfTexture_createFromFile(
        "./game/in_game/pause_in_game/png/menu.png", NULL);
    game->pause->exit_texture = sfTexture_createFromFile(
        "./game/in_game/pause_in_game/png/exit.png", NULL);
}

void set_texture_pause(game_t *game)
{
    sfSprite_setTexture(game->pause->sprite_pause_font,
        game->pause->texture_pause_font, sfTrue);
    sfSprite_setTexture(game->pause->resume_sprite,
        game->pause->resume_texture, sfTrue);
    sfSprite_setTexture(game->pause->menu_sprite,
        game->pause->menu_texture, sfTrue);
    sfSprite_setTexture(game->pause->exit_sprite,
        game->pause->exit_texture, sfTrue);
    sfSprite_setPosition(game->pause->resume_sprite, (sfVector2f) {800, 270});
    sfSprite_setPosition(game->pause->menu_sprite, (sfVector2f) {800, 540});
    sfSprite_setPosition(game->pause->exit_sprite, (sfVector2f) {800, 810});
}

void draw_texture_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->pause->sprite_pause_font, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->pause->resume_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->pause->menu_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->pause->exit_sprite, NULL);
}

void pause_in_game(game_t *game)
{
    create_sprite_pause(game);
    create_texture_pause(game);
    set_texture_pause(game);
}