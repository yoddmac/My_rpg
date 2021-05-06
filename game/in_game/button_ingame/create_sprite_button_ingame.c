/*
** EPITECH PROJECT, 2020
** button_fight
** File description:
** create_sprite_button_ingame
*/

#include "../../../my_rpg.h"

void create_sprite_buttonfight(game_t *game)
{
    game->button_ingame->sprite_attack = sfSprite_create();
}

void create_texture_buttoningame(game_t *game)
{
    game->button_ingame->texture_attack = sfTexture_createFromFile
        ("./game/in_game/png/attack.png", NULL);
}

void set_texture_buttonfight(game_t *game)
{
    sfSprite_setTexture(game->button_ingame->sprite_attack,
        game->button_ingame->texture_attack, sfTrue);
    sfSprite_setPosition(game->button_ingame->sprite_attack,
        (sfVector2f){1400, 600});
}

void draw_texture_buttonfight(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->button_ingame->sprite_attack, NULL);
}

void init_sprite_buttonfight(game_t *game)
{
    create_sprite_buttonfight(game);
    create_texture_buttoningame(game);
    set_texture_buttonfight(game);
}