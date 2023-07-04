/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_second_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void second_zone_npc(call_all_t *call)
{
    if (call->npc_pos[1]->x < 200)
        call->npc_pos[1]->x = 200;
    if (call->npc_pos[1]->x > 600)
        call->npc_pos[1]->x = 600;
    if (call->npc_pos[1]->y < 600)
        call->npc_pos[1]->y = 600;
    if (call->npc_pos[1]->y > 900)
        call->npc_pos[1]->y = 900;
}

void move_second_npc(call_all_t *call, win_t *win)
{
    second_zone_npc(call);
    pattern_second_npc(call, win);
    call->npc_pos[1]->i++;

    move_third_npc(call, win);
}
