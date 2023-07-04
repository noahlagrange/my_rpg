/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** restart_clock
*/

#include "../include/struct.h"

void set_the_clocl(call_all_t *call)
{
    if (call->clock->delta >= 0.128)
        call->clock->delta -= 0.128;
    call->clock->delta += sfTime_asSeconds(
    sfClock_restart(call->clock->clock_move));
}
