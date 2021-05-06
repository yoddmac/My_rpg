/*
** EPITECH PROJECT, 2020
** Inventory
** File description:
** Initialization
*/
#include "../../my_rpg.h"
#include "../../rpg_inventory.h"

void inventory_init(game_t *game)
{
    game->invent->slot_1->empty = 0;
    game->invent->slot_1->name = "Medikit";
    game->invent->slot_1->pos.x = 1650;
    game->invent->slot_1->pos.y = 940;
    game->invent->slot_1->quantity = 0;
    game->invent->slot_1->sprite = sfSprite_create();
    game->invent->slot_1->texture =
        sfTexture_createFromFile("./inventory/src/medikit.png", NULL);
    sfSprite_setTexture(game->invent->slot_1->sprite,
        game->invent->slot_1->texture, NULL);
    game->invent->slot_2->empty = 0;
    game->invent->slot_2->name = "LMG";
    game->invent->slot_2->pos.x = 1750;
    game->invent->slot_2->pos.y = 950;
    game->invent->slot_2->quantity = 0;
    game->invent->slot_2->sprite = sfSprite_create();
    game->invent->slot_2->texture =
        sfTexture_createFromFile("./inventory/src/arme_quete.png", NULL);
    sfSprite_setTexture(game->invent->slot_2->sprite,
        game->invent->slot_2->texture, NULL);
}