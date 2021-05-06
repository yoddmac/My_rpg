/*
** EPITECH PROJECT, 2020
** mouve_perso
** File description:
** mouve_perso
*/

#include "../../my_rpg.h"

void init_rect_perso(game_t *game)
{
    game->perso->rect_perso.height = 54;
    game->perso->rect_perso.width = 45;
    game->perso->y = 1;
    game->perso->x = 1;
}

void mouve_perso_up(game_t *game)
{
    if (game->perso->y <= 0 + 1)
        return;
    if (game->perso->map[game->perso->y - 1][game->perso->x] == -1) {
        game->perso->pos_perso.y -= 16;
        game->perso->y -= 1;
        sfSprite_setPosition(game->perso->sprite_perso, game->perso->pos_perso);
    }
}

void mouve_perso_down(game_t *game)
{
    if (game->perso->y >= game->vertex_map->height - 1)
        return;
    if (game->perso->map[game->perso->y + 1][game->perso->x] == -1) {
        game->perso->pos_perso.y += 16;
        game->perso->y += 1;
        sfSprite_setPosition(game->perso->sprite_perso, game->perso->pos_perso);
    }
}

void mouve_perso_left(game_t *game)
{
    if (game->perso->x <= 0 + 1)
        return;
    if (game->perso->map[game->perso->y][game->perso->x - 1] == -1) {
        game->perso->pos_perso.x -= 16;
        game->perso->x -= 1;
        sfSprite_setPosition(game->perso->sprite_perso, game->perso->pos_perso);
    }
}

void mouve_perso_right(game_t *game)
{
    if (game->perso->x >= game->vertex_map->width - 1)
        return;
    if (game->perso->map[game->perso->y][game->perso->x + 1] == -1) {
        game->perso->pos_perso.x += 16;
        game->perso->x += 1;
        sfSprite_setPosition(game->perso->sprite_perso, game->perso->pos_perso);
    }
}
