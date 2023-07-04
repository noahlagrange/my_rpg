/*
** EPITECH PROJECT, 2023
** block
** File description:
** ////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int block_up(call_all_t *call, coll_t **col)
{
    sfVector2f mou = sfSprite_getPosition(
    call->player[call->info->print]->sprt_player);
    for (int i = 0; col[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(col[i]->rect);
        if (sfFloatRect_contains(&rect, mou.x, mou.y - 25))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x - 13, mou.y - 25))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x + 13, mou.y - 25))
            return 1;
    }
    return 0;
}

int block_dw(call_all_t *call, coll_t **col)
{
    sfVector2f mou = sfSprite_getPosition(
    call->player[call->info->print]->sprt_player);
    for (int i = 0; col[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(col[i]->rect);
        if (sfFloatRect_contains(&rect, mou.x, mou.y + 30))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x - 13, mou.y + 30))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x + 13, mou.y +30))
            return 1;
    }
    return 0;
}

int block_lf(call_all_t *call, coll_t **col)
{
    sfVector2f mou = sfSprite_getPosition(
    call->player[call->info->print]->sprt_player);
    for (int i = 0; col[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(col[i]->rect);
        if (sfFloatRect_contains(&rect, mou.x - 25, mou.y))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x - 25, mou.y - 13))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x - 25, mou.y + 13))
            return 1;
    }
    return 0;
}

int block_rg(call_all_t *call, coll_t **col)
{
    sfVector2f mou = sfSprite_getPosition(
    call->player[call->info->print]->sprt_player);
    for (int i = 0; col[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(col[i]->rect);
        if (sfFloatRect_contains(&rect, mou.x + 25, mou.y))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x + 25, mou.y - 13))
            return 1;
        if (sfFloatRect_contains(&rect, mou.x + 25, mou.y + 13))
            return 1;
    }
    return 0;
}
