/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** animate
*/
#include "../include/struct.h"

void animate_fwd(call_all_t *call)
{
    if (call->clock->delta > 0.124f) {
        call->player[FWD]->dim_sheet.left += 48;
    }
    if (call->player[FWD]->dim_sheet.left >= 144) {
        call->player[FWD]->dim_sheet.left = 0;
    }

    sfSprite_setTextureRect(call->player[FWD]->sprt_player,
    call->player[FWD]->dim_sheet);
    call->dir = FWD;
}

void animate_bwd(call_all_t *call)
{
    if (call->clock->delta > 0.124f) {
        call->player[BWD]->dim_sheet.left += 48;
    }
    if (call->player[BWD]->dim_sheet.left >= 144)
        call->player[BWD]->dim_sheet.left = 0;
    sfSprite_setTextureRect(call->player[BWD]->sprt_player,
    call->player[BWD]->dim_sheet);

    call->dir = BWD;
}

void animate_right(call_all_t *call)
{
    if (call->clock->delta > 0.124f) {
        call->player[RIGHT]->dim_sheet.left += 48;
    }

    if (call->player[RIGHT]->dim_sheet.left >= 144)
        call->player[RIGHT]->dim_sheet.left = 0;

    sfSprite_setTextureRect(call->player[RIGHT]->sprt_player,
    call->player[RIGHT]->dim_sheet);
    call->dir = RIGHT;
}

void animate_left(call_all_t *call)
{
    if (call->clock->delta > 0.124f) {
        call->player[LEFT]->dim_sheet.left += 48;
    }
    if (call->player[LEFT]->dim_sheet.left >= 144)
        call->player[LEFT]->dim_sheet.left = 0;
    sfSprite_setTextureRect(call->player[LEFT]->sprt_player,
    call->player[LEFT]->dim_sheet);
    call->dir = LEFT;
}

void animate_player(call_all_t *call)
{
    if (call->info->print == FWD && call->info->press == 1) {
        animate_fwd(call);
        call->info->press = 0;
    }
    if (call->info->print == BWD && call->info->press == 1) {
        animate_bwd(call);
        call->info->press = 0;
    }
    if (call->info->print == RIGHT && call->info->press == 1) {
        animate_right(call);
        call->info->press = 0;
    }
    if (call->info->print == LEFT && call->info->press == 1) {
        animate_left(call);
        call->info->press = 0;
    }
}
