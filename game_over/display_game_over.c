/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** display_game_over
*/

#include "../include/struct.h"

void cond_display(win_t *win, call_all_t *call, menu_t *menu)
{
    if (call->game_over->scale_game_over.x >= 196.401230) {
        sfRenderWindow_drawText(win->win->win,
        call->game_over->game_over_txt, NULL);
        call->loop->pause = 0;
        sfRenderWindow_setView(win->win->win, call->loop->menu);
        make_menu(menu, win, call, call->loop->view);
        menu->sys->current_states = MENU;
        win->game_states = 1;
        reset_game(call);
    }
}

void display_txt_game_over(win_t *win, call_all_t *call, menu_t *menu)
{
    if (call->loop->perso->pv <= 0) {
        call->loop->pause = 4;
        if (call->game_over->zoom <= 1.028604) {
            call_dezoom(win, call);
            sfRenderWindow_drawText(win->win->win,
            call->game_over->game_over_txt, NULL);
        }
        if (call->game_over->scale_game_over.x <= 196.401230) {
            call->game_over->scale_game_over.x += 0.50;
            call->game_over->scale_game_over.y += 0.50;
            sfText_setScale(call->game_over->game_over_txt,
            call->game_over->scale_game_over);
            sfRenderWindow_drawText(win->win->win,
            call->game_over->game_over_txt, NULL);
        }
        cond_display(win, call, menu);
    }
}
