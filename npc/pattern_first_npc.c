/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pattern_first_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void another_pattern(call_all_t *call, win_t *win)
{
    if (call->npc_pos[0]->i > 500 && call->npc_pos[0]->i < 600) {
        call->npc_pos[0]->x -= 2.5f;
        animated_npc(call, LEFT, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(LEFT, call, win, 0);
    }
    if (call->npc_pos[0]->i > 600 && call->npc_pos[0]->i < 750) {
        call->npc_pos[0]->y -= 2.5f;
        animated_npc(call, UP, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(UP, call, win, 0);
    }
    if (call->npc_pos[0]->i == 750)
        call->npc_pos[0]->i = 0;
}

void again_pattern(call_all_t *call, win_t *win)
{
    if (call->npc_pos[0]->i > 300 && call->npc_pos[0]->i < 400) {
        call->npc_pos[0]->x += 2.5f;
        animated_npc(call, RIGHT, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(RIGHT, call, win, 0);
    }
    if (call->npc_pos[0]->i > 400 && call->npc_pos[0]->i < 500) {
        call->npc_pos[0]->y += 2.5f;
        animated_npc(call, DOWN, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(DOWN, call, win, 0);
    }

    another_pattern(call, win);
}

void continue_pattern(call_all_t *call, win_t *win)
{
    if (call->npc_pos[0]->i > 100 && call->npc_pos[0]->i < 200) {
        call->npc_pos[0]->y += 2.5f;
        animated_npc(call, DOWN, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(DOWN, call, win, 0);

    }
    if (call->npc_pos[0]->i > 200 && call->npc_pos[0]->i < 300) {
        call->npc_pos[0]->x -= 2.5f;
        animated_npc(call, LEFT, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(LEFT, call, win, 0);
    }
    again_pattern(call, win);
}

void pattern_first_npc(call_all_t *call, win_t *win)
{
    if (call->npc_pos[0]->i < 50) {
        call->npc_pos[0]->x += 2.5f;
        animated_npc(call, RIGHT, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(RIGHT, call, win, 0);
    }
    if (call->npc_pos[0]->i > 50 && call->npc_pos[0]->i < 100) {
        call->npc_pos[0]->x += 2.5f;
        animated_npc(call, RIGHT, 233.75, 467.5);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i]->sprite, (sfVector2f)
            {call->npc_pos[0]->x, call->npc_pos[0]->y});
        draw_npc(RIGHT, call, win, 0);
    }
    continue_pattern(call, win);
}
