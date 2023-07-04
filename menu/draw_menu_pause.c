/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** draw_menu_pause
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void draw_pause(menu_t *menu, win_t *win)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    but_for_pause_draw(menu->array_but_pause, win->win->win);
    text_for_pause_draw(menu->array_text_pause, win->win->win);
}

void loop_pause(system_t *sys, win_t *win, menu_t *menu, perso_t *perso)
{
    on_the_block(menu->array_but_pause, win->win->win, sys);
    for (int i = 0; menu->array_but_pause[i] != NULL; i++) {
        pause_states(menu, win, sys, perso);
    }
}
