/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** create_player
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void set_player(call_all_t *call, int nb)
{
    sfSprite_setTexture(call->player[nb]->sprt_player,
    call->player[nb]->player_texture, sfTrue);
    sfSprite_setScale(call->player[nb]->sprt_player, (sfVector2f){1.2, 1.2});
    sfSprite_setTextureRect(call->player[nb]->sprt_player,
    call->player[nb]->dim_sheet);
    sfSprite_setOrigin(call->player[nb]->sprt_player, (sfVector2f){24, 24});
    sfSprite_setPosition(call->player[nb]->sprt_player, (sfVector2f){385, 60});
}

sfSprite *create_player(call_all_t *call, ...)
{
    va_list list;
    va_start(list, call);
    char *sprt_sheet = va_arg(list, char *);
    int width = va_arg(list, int), height = va_arg(list, int),
    nb = va_arg(list, int);
    call->player[nb]->dim_sheet.height = height;
    call->player[nb]->dim_sheet.width = width;
    call->player[nb]->dim_sheet.top = 0;
    call->player[nb]->dim_sheet.left = 0;
    call->player[nb]->player_texture =
    sfTexture_createFromFile(sprt_sheet, NULL);
    call->player[nb]->sprt_player = sfSprite_create();
    call->player[nb]->player_pos = (sfVector2f){385, 60};
    set_player(call, nb);
    va_end(list);
    return call->player[nb]->sprt_player;
}

void launch_create(call_all_t *call)
{
    call->player[FWD]->sprt_player = create_player(call,
    "./assets/charac/player_up.png", 48, 48, FWD);
    call->player[BWD]->sprt_player = create_player(call,
    "./assets/charac/player_down.png", 48, 48, BWD);
    call->player[LEFT]->sprt_player = create_player(call,
    "./assets/charac/player_left.png", 48, 48, LEFT);
    call->player[RIGHT]->sprt_player = create_player(call,
    "./assets/charac/player_right.png", 48, 48, RIGHT);
}
