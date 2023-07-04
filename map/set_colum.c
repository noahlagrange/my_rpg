/*
** EPITECH PROJECT, 2023
** set colum
** File description:
** ////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

colum_t *make_colu(sfVector2f pos)
{
    colum_t *col = malloc(sizeof(colum_t));
    col->spri = sfSprite_create();
    col->tex = sfTexture_createFromFile("assets/map/colum.png", NULL);
    sfSprite_setTexture(col->spri, col->tex, sfTrue);
    sfSprite_setPosition(col->spri, pos);
    return col;
}

void cond_set_colum(colum_t **cols, int *ind, int *pox, int *poy)
{
    *pox = 26;
    *poy = 18;
    for (int i = 0; i < 7; i++) {
        cols[*ind] = make_colu((sfVector2f) {*pox * 32, *poy * 32});
        *pox += 1;
        (*ind)++;
    }
    *pox = 26;
    *poy = 24;
    for (int i = 0; i < 7; i++) {
        cols[*ind] = make_colu((sfVector2f) {*pox * 32, *poy * 32});
        *pox += 1;
        (*ind)++;
    }
}

colum_t **set_colum(void)
{
    colum_t **cols = malloc(sizeof(colum_t *) * 29);
    int pox = 3, poy = 11, ind = 0;
    for (int i = 0; i < 7; i++) {
        cols[ind] = make_colu((sfVector2f) {pox * 32, poy * 32});
        pox += 1;
        ind += 1;
    }
    pox = 26;
    poy = 13;
    for (int i = 0; i < 7; i++) {
        cols[ind] = make_colu((sfVector2f) {pox * 32, poy * 32});
        pox += 1;
        ind++;
    }
    cond_set_colum(cols, &ind, &pox, &poy);
    cols[ind] = NULL;
    return cols;
}
