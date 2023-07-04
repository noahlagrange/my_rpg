/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pattern_fifth_npc
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void end_pattern_third(call_all_t *call, win_t *win)
{
    if (call->npc_pos[2]->i > 160 && call->npc_pos[2]->i < 200) {
        call->npc_pos[2]->y -= 5.0f;
        animated_npc(call, UP + 8, 32.0f, 64.0f);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 8]->sprite, (sfVector2f)
            {call->npc_pos[2]->x, call->npc_pos[2]->y});
        draw_npc(UP + 8, call, win, 8);
    }
    if (call->npc_pos[2]->i == 200) {
        call->npc_pos[2]->i = 0;
    }
}

void continue_pattern_third(call_all_t *call, win_t *win)
{
    if (call->npc_pos[2]->i > 80 && call->npc_pos[2]->i < 120) {
        call->npc_pos[2]->y += 2.5f;
        animated_npc(call, DOWN + 8, 32.0f, 64.0f);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 8]->sprite, (sfVector2f)
            {call->npc_pos[2]->x, call->npc_pos[2]->y});
        draw_npc(DOWN + 8, call, win, 8);
    }
    if (call->npc_pos[2]->i > 120 && call->npc_pos[2]->i < 160) {
        call->npc_pos[2]->x -= 2.5f;
        animated_npc(call, LEFT + 8, 32.0f, 64.0f);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 8]->sprite, (sfVector2f)
            {call->npc_pos[2]->x, call->npc_pos[2]->y});
        draw_npc(LEFT + 8, call, win, 8);
    }
    end_pattern_third(call, win);
}

void pattern_third_npc(call_all_t *call, win_t *win)
{
    if (call->npc_pos[2]->i < 40) {
        call->npc_pos[2]->y += 2.5f;
        animated_npc(call, DOWN + 8, 32.0f, 64.0f);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 8]->sprite, (sfVector2f)
            {call->npc_pos[2]->x, call->npc_pos[2]->y});
        draw_npc(DOWN + 8, call, win, 8);
    }
    if (call->npc_pos[2]->i > 40 && call->npc_pos[2]->i < 80) {
        call->npc_pos[2]->x += 2.5f;
        animated_npc(call, RIGHT + 8, 32.0f, 64.0f);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 8]->sprite, (sfVector2f)
            {call->npc_pos[2]->x, call->npc_pos[2]->y});
        draw_npc(RIGHT + 8, call, win, 8);
    }
    continue_pattern_third(call, win);
}
