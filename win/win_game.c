/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** win_game
*/
#include "../include/struct.h"

void reset_game(call_all_t *call)
{
    for (int i = 0; i < 16; i += 4) {
        call->npc->npc[i]->dead = 0;
        call->npc->npc[i]->hp = 6;
    }
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(call->player[i]->sprt_player,
        (sfVector2f) {385, 60});
}

void back_menu(call_all_t *call, win_t *win, menu_t *menu)
{
    if (call->loop->pause == 3) {
        if (sfKeyboard_isKeyPressed(sfKeyY)) {
            reset_game(call);
            call->loop->pause = 0;
            menu->sys->current_states = MENU;
            win->game_states = 1;
        }
    }
}

void cond_win(call_all_t *call, win_t *win)
{
    if (call->loop->pause == 3)
        sfRenderWindow_drawSprite(win->win->win,
        call->loop->world->end->spri, NULL);
}

void win_game(call_all_t *call, win_t *win)
{
    int nb = 0;
    for (int i = 0; i < 16; i += 4) {
        if (call->npc->npc[i]->dead > 0 && call->npc->npc[i]->dead <= 3) {
            nb++;
            call->npc->npc[i]->dead = 3;
        }
    }
    if (nb == 4)
        call->loop->pause = 3;
    cond_win(call, win);
}
