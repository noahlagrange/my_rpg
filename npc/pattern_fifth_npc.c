/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pattern_third_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void end_pattern_fifth(call_all_t *call, win_t *win)
{
    if (call->npc_pos[3]->i > 240 && call->npc_pos[3]->i < 360) {
        call->npc_pos[3]->x += 3.0f;
        animated_npc(call, RIGHT + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(RIGHT + 12, call, win, 12);
    }
    if (call->npc_pos[3]->i > 360 && call->npc_pos[3]->i < 610) {
        call->npc_pos[3]->x -= 3.0f;
        animated_npc(call, LEFT + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(LEFT + 12, call, win, 12);
    }
    if (call->npc_pos[3]->i == 610)
        call->npc_pos[3]->i = 0;
}

void again_pattern_fifth(call_all_t *call, win_t *win)
{
    if (call->npc_pos[3]->i > 160 && call->npc_pos[3]->i < 200) {
        call->npc_pos[3]->y += 0.0f;
        animated_npc(call, DOWN + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(DOWN + 12, call, win, 12);
    }
    if (call->npc_pos[3]->i > 200 && call->npc_pos[3]->i < 240) {
        call->npc_pos[3]->y -= 1.5f;
        animated_npc(call, UP + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(UP + 12, call, win, 12);
    }

    end_pattern_fifth(call, win);
}

void continue_pattern_fifth(call_all_t *call, win_t *win)
{
    if (call->npc_pos[3]->i > 80 && call->npc_pos[3]->i < 120) {
        call->npc_pos[3]->x += 3.0f;
        animated_npc(call, RIGHT + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(RIGHT + 12, call, win, 12);
    }
    if (call->npc_pos[3]->i > 120 && call->npc_pos[3]->i < 160) {
        call->npc_pos[3]->y += 2.5f;
        animated_npc(call, DOWN + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(DOWN + 12, call, win, 12);
    }
    again_pattern_fifth(call, win);
}

void pattern_fifth_npc(call_all_t *call, win_t *win)
{
    if (call->npc_pos[3]->i < 40) {
        call->npc_pos[3]->x += 3.0f;
        animated_npc(call, DOWN + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(RIGHT + 12, call, win, 12);
    }
    if (call->npc_pos[3]->i > 40 && call->npc_pos[3]->i < 80) {
        call->npc_pos[3]->x += 3.0f;
        animated_npc(call, RIGHT + 12, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 12]->sprite, (sfVector2f)
            {call->npc_pos[3]->x, call->npc_pos[3]->y});
        draw_npc(RIGHT + 12, call, win, 12);
    }
    continue_pattern_fifth(call, win);
}
