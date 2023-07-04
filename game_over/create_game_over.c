/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** create_game_over.
*/

#include "../include/struct.h"

void create_game_over_txt(call_all_t *call)
{
    call->game_over->font_game_over = sfFont_createFromFile
    ("assets/fonts/grasping.ttf");
    call->game_over->game_over_txt = sfText_create();

    sfText_setFont(call->game_over->game_over_txt,
    call->game_over->font_game_over);
    sfText_setColor(call->game_over->game_over_txt, sfRed);
    sfText_setString(call->game_over->game_over_txt, "GAME OVER");
    sfText_setPosition(call->game_over->game_over_txt,
    (sfVector2f){-15920, -7000 / 2});
    call->game_over->scale_game_over = (sfVector2f){0.80, 0.80};
    sfText_setScale(call->game_over->game_over_txt,
    call->game_over->scale_game_over);
}
