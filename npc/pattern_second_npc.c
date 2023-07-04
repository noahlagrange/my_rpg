/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pattern_second_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void end_second_pattern(call_all_t *call, win_t *win)
{
    if (call->npc_pos[1]->i > 580 && call->npc_pos[1]->i < 640) {
        call->npc_pos[1]->y -= 2.5f;
        animated_npc(call, UP + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(UP + 4, call, win, 4);
    }

    if (call->npc_pos[1]->i == 640) {
        call->npc_pos[1]->i = 0;
    }
}

void another_second_pattern(call_all_t *call, win_t *win)
{
    if (call->npc_pos[1]->i > 460 && call->npc_pos[1]->i < 520) {
        call->npc_pos[1]->y += 2.5f;
        animated_npc(call, DOWN + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(DOWN + 4, call, win, 4);
    }
    if (call->npc_pos[1]->i > 520 && call->npc_pos[1]->i < 580) {
        call->npc_pos[1]->x -= 2.5f;
        animated_npc(call, LEFT + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(LEFT + 4, call, win, 4);
    }

    end_second_pattern(call, win);
}

void again_pattern_second(call_all_t *call, win_t *win)
{
    if (call->npc_pos[1]->i > 260 && call->npc_pos[1]->i < 380) {
        call->npc_pos[1]->y -= 2.5f;
        animated_npc(call, UP + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(UP + 4, call, win, 4);
    }
    if (call->npc_pos[1]->i > 380 && call->npc_pos[1]->i < 460) {
        call->npc_pos[1]->x += 2.5f;
        animated_npc(call, RIGHT + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(RIGHT + 4, call, win, 4);
    }

    another_second_pattern(call, win);
}

void continue_pattern_second(call_all_t *call, win_t *win)
{
    if (call->npc_pos[1]->i > 100 && call->npc_pos[1]->i < 180) {
        call->npc_pos[1]->y += 2.5f;
        animated_npc(call, DOWN + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(DOWN + 4, call, win, 4);
    }
    if (call->npc_pos[1]->i > 180 && call->npc_pos[1]->i < 260) {
        call->npc_pos[1]->x -= 2.5f;
        animated_npc(call, LEFT + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(LEFT + 4, call, win, 4);
    }
    again_pattern_second(call, win);
}

void pattern_second_npc(call_all_t *call, win_t *win)
{
    if (call->npc_pos[1]->i < 40) {
        call->npc_pos[1]->y += 2.5f;
        animated_npc(call, DOWN + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(DOWN + 4, call, win, 4);
    }
    if (call->npc_pos[1]->i > 40 && call->npc_pos[1]->i < 100) {
        call->npc_pos[1]->x += 2.5f;
        animated_npc(call, RIGHT + 4, 32.0, 64.0);
        for (int i = 0; i < 4; i++)
            sfSprite_setPosition(call->npc->npc[i + 4]->sprite, (sfVector2f)
            {call->npc_pos[1]->x, call->npc_pos[1]->y});
        draw_npc(RIGHT + 4, call, win, 4);
    }
    continue_pattern_second(call, win);
}
