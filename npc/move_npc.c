/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void first_zone_npc(call_all_t *call)
{
    if (call->npc_pos[0]->x < 1100)
        call->npc_pos[0]->x = 1100;
    if (call->npc_pos[0]->x > 1500)
        call->npc_pos[0]->x = 1500;
    if (call->npc_pos[0]->y < 300)
        call->npc_pos[0]->y = 300;
    if (call->npc_pos[0]->y > 900)
        call->npc_pos[0]->y = 900;
}

void animated_npc(call_all_t *call, int nb, float x, float max)
{
    call->npc_pos[0]->time = sfClock_getElapsedTime(call->npc_pos[0]->clock);
    call->npc_pos[0]->delta = sfTime_asSeconds(call->npc_pos[0]->time);
    call->npc->npc[nb]->next = sfSprite_getTextureRect
    (call->npc->npc[nb]->sprite);
    if (call->npc_pos[0]->delta > 0.40f) {
        if (call->npc->npc[nb]->next.left >= max) {
            call->npc->npc[nb]->next.left = 0;
        } else {
            call->npc->npc[nb]->next.left += x;
        }
        sfSprite_setTextureRect(call->npc->npc[nb]->sprite,
        call->npc->npc[nb]->next);
    }
}

void move_npc(call_all_t *call, win_t *win)
{
    first_zone_npc(call);
    pattern_first_npc(call, win);
    call->npc_pos[0]->i++;

    move_second_npc(call, win);
}
