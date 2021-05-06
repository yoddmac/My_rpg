/*
** EPITECH PROJECT, 2020
** gest_button
** File description:
** gest_buttonfight
*/

#include "../../../my_rpg.h"

void menu_button_attack(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfIntRect attack_rect = sfSprite_getTextureRect
        (game->button_ingame->sprite_attack);
    attack_rect.left = 1400;
    attack_rect.top = 600;

    if (game->window->scene < 5 || game->window->scene > 7 )
        return;
    sfSprite_setTexture(game->button_ingame->sprite_attack,
        game->button_ingame->texture_attack, sfTrue);
    if (mouse.x >= attack_rect.left && mouse.x <= attack_rect.left +
        attack_rect.width) {
        if (mouse.y >= attack_rect.top && mouse.y <= attack_rect.top +
                attack_rect.height && game->window->event.type ==
                sfEvtMouseButtonPressed) {
            game->button_ingame->change = 1;
        }
    }
}