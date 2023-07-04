/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void draw_player_and_hitbox(call_all_t *call, win_t *win)
{
    for (int i = 0; i != 4; i++)
        sfRectangleShape_setPosition(call->npc->rec[2]->rect, (sfVector2f)
        {call->player[i]->player_pos.x, call->player[i]->player_pos.y});
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawRectangleShape(win->win->win,
        call->npc->rec[i]->rect, NULL);
}

void event(win_t *win, coll_t **col, call_all_t *call)
{
    (void)col;
    move_npc(call, win);
    sfRenderWindow_drawSprite(win->win->win,
    call->player[call->dir]->sprt_player, NULL);
}
