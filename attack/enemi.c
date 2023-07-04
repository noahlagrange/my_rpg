/*
** EPITECH PROJECT, 2023
** enemi
** File description:
** ////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

enemi_t *make_ene(void)
{
    enemi_t* ene = malloc(sizeof(enemi_t));
    ene->rect = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(ene->rect, sfRed);
    sfRectangleShape_setFillColor(ene->rect, sfRed);
    sfRectangleShape_setSize(ene->rect, (sfVector2f) {64, 64});
    sfRectangleShape_setPosition(ene->rect, (sfVector2f){400, 800});
    ene->hp = 6;
    ene->dead = 0;
    return ene;
}

void cac_deg(call_all_t *call, attack_t *att, perso_t *per)
{
    for (int i = 0; i < 16; i++) {
        if (att->act == 0 || att->touch == 1 || call->npc->npc[i]->dead == 1)
            return;
        sfFloatRect rect1 = sfSprite_getGlobalBounds(call->npc->npc[i]->sprite);
        sfFloatRect rect2 = sfSprite_getGlobalBounds(att->sprite);
        if (sfFloatRect_intersects(&rect1, &rect2, &rect2) == sfTrue) {
            call->npc->npc[i]->hp -= per->deg;
            att->touch = 1;
        }
    }
}

sfSprite *shot_deg(call_all_t *call, sfSprite *spri, loop_t *loop)
{
    if (spri == NULL || loop->shot->touch == 1)
        return spri;
    for (int i = 0; i < 16; i++) {
        sfFloatRect rect1 = sfSprite_getGlobalBounds(call->npc->npc[i]->sprite);
        sfFloatRect rect2 = sfSprite_getGlobalBounds(spri);
        if (sfFloatRect_intersects(&rect1, &rect2, &rect2) == sfTrue) {
            call->npc->npc[i]->hp -= 4;
            loop->shot->touch = 1;
        }
    }
    return spri;
}
