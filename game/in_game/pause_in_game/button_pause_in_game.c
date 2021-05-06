/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_pause_in_game
*/

#include "../../../my_rpg.h"

void button_resume_in_game(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect resume = sfSprite_getTextureRect(game->pause->resume_sprite);
    resume.left = 800;
    resume.top = 270;

    sfSprite_setTexture(game->pause->resume_sprite,
        game->pause->resume_texture, sfTrue);
    if (mouse.x >= resume.left && mouse.x <= resume.left + resume.width) {
        if (mouse.y >= resume.top && mouse.y <= resume.top + resume.height &&
            game->window->event.type == sfEvtMouseButtonPressed) {
            game->pause->scene = 2;
        }
    }
}

void button_menu_in_game(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect menu = sfSprite_getTextureRect(game->pause->menu_sprite);
    menu.left = 800;
    menu.top = 540;

    sfSprite_setTexture(game->pause->menu_sprite,
        game->pause->menu_texture, sfTrue);
    if (mouse.x >= menu.left && mouse.x <= menu.left + menu.width) {
        if (mouse.y >= menu.top && mouse.y <= menu.top + menu.height &&
            game->window->event.type == sfEvtMouseButtonPressed) {
            game->pause->scene = 3;
        }
    }
}

void button_exit_in_game(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect exit = sfSprite_getTextureRect(game->pause->exit_sprite);
    exit.left = 800;
    exit.top = 810;

    sfSprite_setTexture(game->pause->exit_sprite,
        game->pause->exit_texture, sfTrue);
    if (mouse.x >= exit.left && mouse.x <= exit.left + exit.width) {
        if (mouse.y >= exit.top && mouse.y <= exit.top + exit.height &&
            game->window->event.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(game->window->window);
        }
    }
}

void button_pause_in_game(game_t *game)
{
    button_resume_in_game(game);
    button_menu_in_game(game);
    button_exit_in_game(game);
}