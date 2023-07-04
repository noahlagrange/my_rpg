/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init_all
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void init_npc_pos(call_all_t *call)
{
    for (int i = 0; i <= 4; i++) {
        call->npc_pos[i] = malloc(sizeof(npc_pos_t));
        call->npc_pos[i]->npc_img = malloc(sizeof(npc_img_t));
        call->npc_pos[i]->i = 0;
        call->npc_pos[i]->x = 0;
        call->npc_pos[i]->y = 0;
    }
    call->npc->clock = sfClock_create();
}

call_all_t *init_npc(call_all_t *call)
{
    call->npc = malloc(sizeof(all_npc_t));
    call->npc->npc = malloc(sizeof(npc_img_t) * 16);
    for (int i = 0; i < 16; i++) {
        call->npc->npc[i] = malloc(sizeof(npc_img_t));
        call->npc->npc[i]->next.top = 0;
        call->npc->npc[i]->next.height = 0;
        call->npc->npc[i]->next.width = 0;
        call->npc->npc[i]->next.left = 0;
        call->npc->npc[i]->sprite = NULL;
        call->npc->npc[i]->texture = NULL;
        call->npc->npc[i]->dead = 0;
        call->npc->npc[i]->touch = 0;
        call->npc->npc[i]->hp = 6;
    }
    call->npc->rec = malloc(sizeof(zone_npc_t*) * 3);
    call->clock = malloc(sizeof(clock_move_t));
    call->npc_pos = malloc(sizeof(npc_pos_t) * 4);
    init_npc_pos(call);
    call->dir = 0;
    return call;
}

void init_player(call_all_t *call)
{
    call->player = malloc(sizeof(player_move_t) * (4));
    call->game_over = malloc(sizeof(game_over_t));
    for (int cpt = 0; cpt <= 4; cpt++) {
        call->player[cpt] = malloc(sizeof(player_move_t));
    }
    call->info = malloc(sizeof(info_t));
    call->info->print = 0;
    call->info->press = 0;
}
