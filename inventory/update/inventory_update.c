/*
** EPITECH PROJECT, 2020
** Inventory
** File description:
** Initialization
*/
#include "../../my_rpg.h"

void inventory_update(game_t *game)
{
    if (game->invent->slot_1->quantity == 0)
        game->invent->slot_1->empty = 0;
    else
        game->invent->slot_1->empty = 1;
    if (game->invent->slot_2->quantity == 0)
        game->invent->slot_2->empty = 0;
    else
        game->invent->slot_2->empty = 1;
    sfSprite_setPosition(game->invent->slot_1->sprite,
        game->invent->slot_1->pos);
    sfSprite_setPosition(game->invent->slot_2->sprite,
        game->invent->slot_2->pos);
}

void click_invent(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    if (((mouse.y >= 940 && mouse.y <= 1053) && mouse.x >= 1650
        && mouse.x <= 1768)) {
        if (game->window->event.type == sfEvtMouseButtonPressed
                && game->invent->slot_1->quantity > 0) {
            sfSound_play(game->sound->sound_heal);
            game->invent->slot_1->quantity -= 1;
            game->perso->perso_life = game->perso->perso_max_health;
        }
    }
}