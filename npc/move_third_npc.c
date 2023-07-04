/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_third_npc
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void third_zone_npc(call_all_t *call)
{
    if (call->npc_pos[2]->x < 650)
        call->npc_pos[2]->x = 650;
    if (call->npc_pos[2]->x > 750)
        call->npc_pos[2]->x = 750;
    if (call->npc_pos[2]->y < 600)
        call->npc_pos[2]->y = 600;
    if (call->npc_pos[2]->y > 800)
        call->npc_pos[2]->y = 800;
}

void move_third_npc(call_all_t *call, win_t *win)
{
    third_zone_npc(call);
    pattern_third_npc(call, win);
    call->npc_pos[2]->i++;

    move_fifth_npc(call, win);
}
