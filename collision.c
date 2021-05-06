/*
** EPITECH PROJECT, 2020
** scene
** File description:
** scene
*/

#include "my_rpg.h"

int **itoitab(int *int_tab, int x, int y)
{
    int c = 0;
    int i = 0;
    int j = 0;
    int **d_int_tab = malloc(sizeof(int *) * (y + 1));

    for (int k = 0; k <= y; k++)
        d_int_tab[k] = malloc(sizeof(int) * (x + 1));
    for (i = 0; i <= y; i++) {
        for (j = 0; j <= x; j++, c++) {
            d_int_tab[i][j] = int_tab[c];
        }
        c--;
    }
    return (d_int_tab);
}

void get_which_tile(game_t *game)
{
    sfVector2f pos_s = sfSprite_getPosition(game->perso->sprite_perso);
    int i = pos_s.y / 10 + 1;
    int j = pos_s.x / 10 + 1;

    game->perso->tile = game->perso->map[i][j];
}

