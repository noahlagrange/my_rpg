/*
** EPITECH PROJECT, 2023
** draw all
** File description:
** //////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void draw_pro(profile_t *pro, perso_t *per, sfSprite *inv, sfRenderWindow *win)
{
    print_pro(pro, per);
    sfRenderWindow_drawSprite(win, inv, NULL);
    sfRenderWindow_drawText(win, pro->tpv, NULL);
    sfRenderWindow_drawText(win, pro->tarmor, NULL);
    sfRenderWindow_drawText(win, pro->texp, NULL);
    sfRenderWindow_drawText(win, pro->tgold, NULL);
    sfRenderWindow_drawText(win, pro->niv, NULL);
    sfRenderWindow_drawText(win, pro->tdeg, NULL);
    if (per->pomme == 1)
        sfRenderWindow_drawSprite(win, pro->sprite, NULL);
    if (per->get_armor == 1)
        sfRenderWindow_drawSprite(win, pro->armor, NULL);
}
