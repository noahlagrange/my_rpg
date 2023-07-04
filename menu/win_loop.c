/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** win_loop
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void key_event(menu_t *menu, win_t *win)
{
    if (win->ev.type == sfEvtKeyPressed) {
        if ((win->ev.key.code == sfKeyEscape) &&
        ((menu->sys->current_states == PLAY) ||
        (menu->sys->current_states == RESUME)))
            menu->sys->current_states = PAUSE;
        if ((win->ev.key.code == sfKeyEscape) &&
        (menu->sys->current_states != PLAY) &&
        (menu->sys->current_states != RESUME) &&
        (menu->sys->current_states != PAUSE) &&
        (menu->sys->current_states_pause != RESUME_GAME))
            menu->sys->current_states = MENU;
        if ((menu->sys->current_states_pause == LEAVE) ||
        (menu->sys->current_states_pause == SAVE))
            menu->sys->current_states = MENU;
    }
    key_event2(menu, win);
}

void states_actions(menu_t *menu, win_t *win, call_all_t *call)
{
    if (win->game_states == 1)
        make_menu(menu, win, call, call->loop->menu);
    if (win->game_states == 2)
        make_play(call, win, call->loop->world, menu);
    if (win->game_states == 6 || win->game_states == 10)
        make_menu(menu, win, call, call->loop->menu);
    if (win->game_states == 7) {
        make_play(call, win, call->loop->world, menu);
    }
}

void states_actions2(menu_t *menu, sound_t *music, win_t *win, call_all_t *call)
{
    if (win->game_states == 3 && menu->sys->current_states_settings != 3)
        make_settings(menu, menu->sys, music, win);
    if (win->game_states == 3 && menu->sys->current_states_settings == 3)
        make_how(menu, win);
    if (win->game_states == 5)
        make_pause(menu->sys, menu, win, call->loop);
    if (win->game_states == 9)
        make_about(menu, win);
}

void window_loop(menu_t *menu, win_t *win, call_all_t *call, sound_t *music)
{
    call->loop = make_loop(win);
    init_all_game(call);
    while (sfRenderWindow_isOpen(win->win->win)) {
        set_the_clocl(call);
        set_the_view(call->loop->pause, call->loop->view,
        call->player[call->dir]->sprt_player, win->game_states);
        while (sfRenderWindow_pollEvent(win->win->win, &win->ev)) {
            back_menu(call, win, menu);
            event_game(win, call, call->loop);
            win->game_states = manage_global(menu);
            key_event(menu, win);
            move_player(call, win, call->loop->col);
            cond_pause(call->loop, call, win, call->loop->world);
        }
        states_actions(menu, win, call);
        states_actions2(menu, music, win, call);
        sfRenderWindow_display(win->win->win);
    }
}

void loop_menu(win_t *win, menu_t *menu, call_all_t *call)
{
    on_the_block(menu->array_but_menu, win->win->win,  menu->sys);
    for (int i = 0;menu->array_but_menu[i] != NULL;i++) {
        menu_states(win, menu, call);
    }
}
