/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** take_damage
*/
#include "../include/struct.h"

void check_damage(call_all_t *call, sfVector2f pos_player)
{
    for (int i = 0; i < 16; i += 4) {
        const sfFloatRect pos_npc = sfSprite_getGlobalBounds
        (call->npc->npc[i]->sprite);
        if (sfFloatRect_contains(&pos_npc, pos_player.x, pos_player.y)
        && call->npc->npc[i]->dead == 0) {
            call->loop->perso->pv -= 5 - call->loop->perso->amors;
            sfClock_restart(call->npc->clock);
        }
    }
}

void take_damage(call_all_t *call)
{
    call->npc->time = sfClock_getElapsedTime(call->npc->clock);
    call->npc->delta = sfTime_asSeconds(call->npc->time);
    sfVector2f pos_player = sfSprite_getPosition
    (call->player[DOWN]->sprt_player);
    if (call->npc->delta >= 1.0f) {
        check_damage(call, pos_player);
    }
}
