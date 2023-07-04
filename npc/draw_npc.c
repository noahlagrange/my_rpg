/*
** EPITECH PROJECT, 2023
** draw_sprite
** File description:
** draw_npc
*/

#include "../include/struct.h"

void draw_npc(int dir, call_all_t *call, win_t *win, int ind)
{
    if (call->npc->npc[ind]->hp > 0)
        sfRenderWindow_drawSprite(win->win->win,
        call->npc->npc[dir]->sprite, NULL);
}
