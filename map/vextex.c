/*
** EPITECH PROJECT, 2023
** vertexarr
** File description:
** /////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void set_quad(map_t *arr, sfVertexArray *carre, int i, sfTexture *text)
{
    for (int j = 0; j < arr->y; j++) {
        int tileNumber = arr->map[i + j * arr->x];
        int tu = tileNumber % (sfTexture_getSize(text).x / 32);
        int tv = tileNumber / (sfTexture_getSize(text).x / 32);
        sfVertex *quad = sfVertexArray_getVertex(carre, (i + j * arr->x) * 4);
        quad[0].position = (sfVector2f){i * 32, j * 32};
        quad[1].position = (sfVector2f){(i + 1) * 32, j * 32};
        quad[2].position = (sfVector2f){(i + 1) * 32, (j + 1) * 32};
        quad[3].position = (sfVector2f){i * 32, (j + 1) * 32};
        quad[0].texCoords = (sfVector2f) {tu * 32, tv * 32};
        quad[1].texCoords = (sfVector2f){(tu + 1) * 32, tv * 32};
        quad[2].texCoords = (sfVector2f){(tu + 1) * 32, (tv + 1) * 32};
        quad[3].texCoords = (sfVector2f){tu * 32, (tv + 1) * 32};
    }
}

sfVertexArray *fonc(map_t *arr)
{
    sfTexture *text = sfTexture_createFromFile("assets/map/final.png", NULL);
    sfVertexArray *carre = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(carre, sfQuads);
    sfVertexArray_resize(carre, arr->x * arr->y * 4);
    for (int i = 0; i < arr->x; i++) {
        for (int j = 0; j < arr->y; j++) {
            set_quad(arr, carre, i, text);
        }
    }
    return carre;
}

vertex_t *make_vertex(map_t *arr)
{
    vertex_t *ver = malloc(sizeof(vertex_t));
    ver->carre = fonc(arr);
    sfTexture *text = sfTexture_createFromFile("assets/map/final.png", NULL);
    ver->al = make_state(text);
    return ver;
}
