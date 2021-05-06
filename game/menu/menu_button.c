/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_button
*/

#include "../../my_rpg.h"

void menu_button_start(game_t *game)
{
    menu_button_start_next(game);
    if (game->window->scene == 1)
        return;
}

void menu_button_start_next(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect start_rect = sfSprite_getTextureRect(game->menu->start_sprite);
    start_rect.left = 800;
    start_rect.top = 270;
    if (mouse.y >= 309 && mouse.y <= 423 && mouse.x >= 833 && mouse.x <= 1099) {
            sfSprite_setTexture(game->menu->start_sprite,
                game->menu->start2_texture, sfTrue);
        if (mouse.y >= start_rect.top && mouse.y <= start_rect.top +
                start_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed) {
            game->window->scene = 1;
            game->sound->song_scene = 1;
            sfSound_play(game->sound->sound_click);
            sfSound_play(game->sound->sound_typewriter);
        }
    }
}

void call_all_button(game_t *game)
{
    menu_button_go(game);
    menu_button_go_speak(game);
    menu_button_start(game);
    menu_button_option(game);
    click_invent(game);
    menu_button_quit(game);
}