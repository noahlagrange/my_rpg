/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** exp
*/
#include "../include/struct.h"

void check_hp(call_all_t *call)
{
    for (int i = 0; i < 4; i++) {
        if (call->npc->npc[i]->hp <= 0 &&
        call->npc->npc[i]->dead == 0)
            call->npc->npc[i]->dead = 1;
    }
    for (int i = 0; i < 4; i++) {
        if (call->npc->npc[i + 4]->hp <= 0 &&
        call->npc->npc[i + 4]->dead == 0)
            call->npc->npc[i + 4]->dead = 1;
    }
    for (int i = 0; i < 4; i++) {
        if (call->npc->npc[i + 8]->hp <= 0 &&
        call->npc->npc[i + 8]->dead == 0)
            call->npc->npc[i + 8]->dead = 1;
    }
    for (int i = 0; i < 4; i++) {
        if (call->npc->npc[i + 12]->hp <= 0 &&
        call->npc->npc[i + 12]->dead == 0)
            call->npc->npc[i + 12]->dead = 1;
    }
}

void make_exp(call_all_t *call, perso_t *perso)
{
    if (call->npc->npc[0]->dead == 1) {
        perso->exp += 50;
        perso->gold += 5;
        call->npc->npc[0]->dead = 2;
    }
    if (call->npc->npc[4]->dead == 1) {
        perso->exp += 50;
        perso->gold += 5;
        call->npc->npc[4]->dead = 2;
    }
    if (call->npc->npc[8]->dead == 1) {
        perso->exp += 50;
        perso->gold += 5;
        call->npc->npc[8]->dead = 2;
    }
    if (call->npc->npc[12]->dead == 1) {
        perso->exp += 50;
        perso->gold += 5;
        call->npc->npc[12]->dead = 2;
    }
}

void exp_gain(call_all_t *call, perso_t *perso)
{
    check_hp(call);
    make_exp(call, perso);
}
