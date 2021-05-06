/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** vector creation
*/

#include "../../my_rpg.h"

int *parsing_csv_props (int width, int height)
{
    int *int_tab = malloc(width * height * (sizeof(int)));
    char *buffer = NULL;
    size_t size = 0;
    FILE *fp = fopen("./survival_fond.csv" , "r");
    char *token = NULL;
    int x = 0;

    while (getline(&buffer, &size, fp) > 0) {
        token = my_strtok(buffer, ",");
        while (token != NULL) {
            int_tab[x] = my_getnbr(token);
            token = my_strtok(NULL, ",");
            x++;
        }
    }
    return (int_tab);
}

vertex_t *initialisation_vertex_props(void)
{
    vertex_t *vertex = malloc(sizeof(vertex_t));

    vertex->tiles_text = sfTexture_createFromFile
        ("./game/window/map_survival.png", NULL);
    vertex->pos.x = 16;
    vertex->pos.y = 16;
    vertex->width = 60;
    vertex->height = 32;
    vertex->state.shader = NULL;
    vertex->state.blendMode = sfBlendAlpha;
    vertex->state.transform = sfTransform_Identity;
    vertex->state.texture = vertex->tiles_text;

    return (vertex);
}

void tiles_info(vertex_t *vertex, sfVertexArray *vertex_tab, int *parse_csv)
{
    for (unsigned int i = 0; i < vertex->width; i++)
        for (unsigned int j = 0; j < vertex->height; j++) {
            int tileNumber = parse_csv[i + j * vertex->width];
            int tu = tileNumber % (sfTexture_getSize(vertex->tiles_text).x / 32);
            int tv = tileNumber / (sfTexture_getSize(vertex->tiles_text).x / 32);
            if (tileNumber == -1)
                continue;
            sfVertex *quad = sfVertexArray_getVertex(vertex_tab, (i + j * vertex->width) * 4);
            quad[0].position = (sfVector2f) {i * vertex->pos.x, j * vertex->pos.y};
            quad[1].position = (sfVector2f) {(i + 1) * vertex->pos.x, j * vertex->pos.y};
            quad[2].position = (sfVector2f) {(i + 1) *
                vertex->pos.x, (j + 1) * vertex->pos.y};
            quad[3].position = (sfVector2f) {i * vertex->pos.x, (j + 1) * vertex->pos.y};
            quad[0].texCoords = (sfVector2f) {tu * vertex->pos.x, tv * vertex->pos.y};
            quad[1].texCoords = (sfVector2f) {(tu + 1) * vertex->pos.x, tv * vertex->pos.y};
            quad[2].texCoords =
                (sfVector2f) {(tu + 1) * vertex->pos.x, (tv + 1) * vertex->pos.y};
            quad[3].texCoords = (sfVector2f) {tu * vertex->pos.x, (tv + 1) * vertex->pos.y};
        }
}

sfVertexArray *create_vertex(vertex_t *vertex, int *parse_csv, int width,
    int height)
{
    sfVertexArray *vertex_tab = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(vertex_tab, sfQuads);
    sfVertexArray_resize(vertex_tab, width * height * 4);
    tiles_info(vertex, vertex_tab, parse_csv);

    return (vertex_tab);
}