/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** game_over
*/

#include "../include/struct.h"

void create_game_over(call_all_t *call)
{
    call->game_over->view = sfView_create();
    sfView_setCenter(call->game_over->view, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(call->game_over->view, (sfVector2f){1920.0f, 1080.0f});
    call->game_over->zoom = 1.0f;
}

void dezoom_view(win_t *win, call_all_t *call)
{
    call->game_over->zoom += 0.00010f;
    sfView_zoom(call->loop->view, call->game_over->zoom);
    sfRenderWindow_setView(win->win->win, call->loop->view);
}

void call_dezoom(win_t *win, call_all_t *call)
{
    dezoom_view(win, call);
}
