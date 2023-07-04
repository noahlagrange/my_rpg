/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_fifth_npc
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void fifth_zone_npc(call_all_t *call)
{
    if (call->npc_pos[3]->x < 650)
        call->npc_pos[3]->x = 650;
    if (call->npc_pos[3]->x > 1250)
        call->npc_pos[3]->x = 1250;
    if (call->npc_pos[3]->y < 100)
        call->npc_pos[3]->y = 100;
    if (call->npc_pos[3]->y > 250)
        call->npc_pos[3]->y = 250;
}

void move_fifth_npc(call_all_t *call, win_t *win)
{
    fifth_zone_npc(call);
    pattern_fifth_npc(call, win);
    call->npc_pos[3]->i++;
}
