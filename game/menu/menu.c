/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** menu
*/

#include "../../my_rpg.h"

void menu_button_option(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect option_rect = sfSprite_getTextureRect(game->menu->option_sprite);
    option_rect.left = 800;
    option_rect.top = 540;

    sfSprite_setTexture(game->menu->option_sprite,
        game->menu->option_texture, sfTrue);
    if (((mouse.y >= 577 && mouse.y <= 691) &&
            mouse.x >= 817 && mouse.x <= 1083)) {
            sfSprite_setTexture(game->menu->option_sprite,
                game->menu->option2_texture, sfTrue);
        if (mouse.y >= option_rect.top && mouse.y <= option_rect.top +
                option_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed) {
            sfSound_play(game->sound->sound_click);
            game->window->scene = 3;
            }
    }
}

void menu_button_go(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect go_rect = sfSprite_getTextureRect(game->menu->go_sprite);
    go_rect.left = 1400;
    go_rect.top = 800;
    sfSprite_setTexture(game->menu->go_sprite, game->menu->go_texture, sfTrue);

    if (mouse.x >= go_rect.left && mouse.x <= go_rect.left +
        go_rect.width) {
        if (mouse.y >= go_rect.top && mouse.y <= go_rect.top +
            go_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed) {
            game->window->scene = 1;
            game->menu->end_story = 1;
            sfSound_stop(game->sound->sound_typewriter);
        }
    }
}

void menu_button_go_speak(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect go_rect = sfSprite_getTextureRect(game->menu->go_sprite);
    go_rect.left = 1400;
    go_rect.top = 800;

    sfSprite_setTexture(game->menu->go_sprite, game->menu->go_texture, sfTrue);
        if (mouse.x >= go_rect.left && mouse.x <= go_rect.left +
            go_rect.width) {
            if (mouse.y >= go_rect.top && mouse.y <= go_rect.top +
                go_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed && game->perso->speak == 1) {
                sfSprite_setPosition(game->perso->sprite_speakpnj,
                    (sfVector2f){3000, 3000});
                sfSprite_setPosition(game->menu->go_sprite,
                    (sfVector2f){3000, 3000});
        }
    }
}

void menu_button_quit(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect quit_rect = sfSprite_getTextureRect(game->menu->quit_sprite);
    quit_rect.left = 800;
    quit_rect.top = 810;

    if (game->window->scene == 1)
        return;
    sfSprite_setTexture(game->menu->quit_sprite,
        game->menu->quit_texture, sfTrue);
    if (mouse.y >= 854 && mouse.y <= 968 && mouse.x >= 853 && mouse.x <= 1119) {
            sfSprite_setTexture(game->menu->quit_sprite,
                game->menu->quit2_texture, sfTrue);
        if (mouse.y >= quit_rect.top && mouse.y <= quit_rect.top +
                quit_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed) {
            sfSound_play(game->sound->sound_click);
            sfRenderWindow_close(game->window->window);
        }
    }
}