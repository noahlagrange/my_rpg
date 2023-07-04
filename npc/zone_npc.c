/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** zone_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void zone_npc(call_all_t *call)
{
    call->npc->rec[0] = create_rectangle((sfVector2f) {1250, 500},
    (sfVector2f) {250, 250});
    call->npc->rec[1] = create_rectangle((sfVector2f) {1250, 500},
    (sfVector2f) {45, 60});
    call->npc->rec[2] = create_rectangle((sfVector2f) {600, 900},
    (sfVector2f) {55, 70});
}

zone_npc_t *create_rectangle(sfVector2f position, sfVector2f size)
{
    zone_npc_t *rect = malloc(sizeof(zone_npc_t));
    rect->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect->rect, size);
    sfRectangleShape_setPosition(rect->rect, position);
    sfRectangleShape_setFillColor(rect->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect->rect, 1);
    return rect;
}
