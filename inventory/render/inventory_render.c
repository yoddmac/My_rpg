/*
** EPITECH PROJECT, 2020
** Inventory
** File description:
** Initialization
*/
#include "../../my_rpg.h"

void inventory_render(game_t *game)
{
    if (game->invent->slot_1->empty == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->invent->slot_1->sprite, NULL);
    if (game->invent->slot_2->empty == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->invent->slot_2->sprite, NULL);
}