/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** move_player
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void move_fwd(call_all_t *call, win_t *win, coll_t **col)
{
    if (win->ev.type == sfEvtKeyPressed && block_up(call, col) == 0
    && win->ev.key.code == sfKeyZ) {
        call->info->print = FWD;
        call->info->press = 1;
        for (int cpt = 0; cpt != 4; cpt++)
            sfSprite_move(call->player[cpt]->sprt_player,
            (sfVector2f){0, -100 * call->clock->delta});
        sfView_move(call->loop->view, (sfVector2f)
        {0, -100 * call->clock->delta});
    }
}

void move_bwd(call_all_t *call, win_t *win, coll_t **col)
{
    if (win->ev.type == sfEvtKeyPressed && block_dw(call, col) == 0
    && win->ev.key.code == sfKeyS) {
        call->info->print = BWD;
        call->info->press = 1;
        for (int cpt = 0; cpt != 4; cpt++)
            sfSprite_move(call->player[cpt]->sprt_player,
            (sfVector2f){0, 100 * call->clock->delta});
        sfView_move(call->loop->view, (sfVector2f)
        {0, 100 * call->clock->delta});
    }
}

void move_right(call_all_t *call, win_t *win, coll_t **col)
{
    if (win->ev.type == sfEvtKeyPressed && block_rg(call, col) == 0
    && win->ev.key.code == sfKeyD) {
        call->info->print = RIGHT;
        call->info->press = 1;
        for (int cpt = 0; cpt != 4; cpt++)
            sfSprite_move(call->player[cpt]->sprt_player,
            (sfVector2f){100 * call->clock->delta, 0});
        sfView_move(call->loop->view, (sfVector2f)
        {100 * call->clock->delta, 0});
    }
}

void move_left(call_all_t *call, win_t *win, coll_t **col)
{
    if (win->ev.type == sfEvtKeyPressed && block_lf(call, col) == 0
    && win->ev.key.code == sfKeyQ) {
        call->info->print = LEFT;
        call->info->press = 1;
        for (int cpt = 0; cpt != 4; cpt++)
            sfSprite_move(call->player[cpt]->sprt_player,
            (sfVector2f){-100 * call->clock->delta, 0});
        sfView_move(call->loop->view, (sfVector2f)
        {-100 * call->clock->delta, 0});
    }
}

void move_player(call_all_t *call, win_t *win, coll_t **col)
{
    move_fwd(call, win, col);
    move_bwd(call, win, col);
    move_left(call, win, col);
    move_right(call, win, col);
}
