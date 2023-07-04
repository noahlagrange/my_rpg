/*
** EPITECH PROJECT, 2023
** colli
** File description:
** p2_map
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

coll_t *make_col(int *i, int *j)
{
    coll_t *col = malloc(sizeof(coll_t));
    col->rect = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(col->rect, 5.0);
    sfRectangleShape_setOutlineColor(col->rect, sfRed);
    sfRectangleShape_setSize(col->rect, (sfVector2f) {32, 32});
    sfRectangleShape_setPosition(col->rect, (sfVector2f) {*i * 32, *j * 32});
    return col;
}

coll_t **set_all(coll_t **arr, int *i, int *j)
{
    int ind = 0;
    if (arr == NULL) {
        arr = malloc(sizeof(coll_t *) * 2);
        arr[0] = make_col(&*i, &*j);
        arr[1] = NULL;
        return arr;
    }
    for (int i = 0; arr[i] != NULL; i++)
        ind++;
    coll_t **res = malloc(sizeof(coll_t *) * (ind + 2));
    for (int i = 0; arr[i] != NULL; i++) {
        res[i] = malloc(sizeof(coll_t));
        res[i] = arr[i];
    }
    res[ind] = make_col(&*i, &*j);
    res[ind + 1] = NULL;
    return res;
}

coll_t **set_col(map_t *arr)
{
    coll_t **colli = NULL;
    for (int i = 0; i < arr->x; i++) {
        for (int j = 0; j < arr->y; j++) {
        int tileNumber = arr->map[i + j * arr->x];
        (tileNumber >= 5 ? colli = set_all(colli, &i, &j) : 0);
        }
    }
    return colli;
}
