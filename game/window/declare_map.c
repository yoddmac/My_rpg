/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** declare_map
*/

#include "../../my_rpg.h"

void declare_map(game_t *game)
{
    game->vertex_map = initialisation_vertex();
    int *pars_csv = parsing_csv(game->vertex_map->width,
        game->vertex_map->height);
    int *pars_csv_props = parsing_props_csv(game->vertex_map->width,
        game->vertex_map->height);
    game->vertex_map->map_array = create_vertex(game->vertex_map, pars_csv,
        game->vertex_map->width, game->vertex_map->height);
    game->vertex_map->map_props = create_vertex(game->vertex_map,
        pars_csv_props, game->vertex_map->width, game->vertex_map->height);
    game->perso->map = itoitab(pars_csv_props,
        game->vertex_map->width, game->vertex_map->height);
}