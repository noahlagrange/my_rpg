/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** fonc_draw
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void draw_menu(menu_t *menu, win_t *win)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    draw_background_menu(menu->back, win->win->win);
    but_draw(menu->array_but_menu, win->win->win);
    text_draw(menu->array_text_menu, win->win->win);
    draw_title(menu->title, win);
}

void draw_settings(menu_t *menu, win_t *win)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    draw_background_settings(menu->back, win->win->win);
    but_for_settings_draw(menu->array_but_settings, win->win->win);
    text_for_settings_draw(menu->array_text_settings, win->win->win);
}

void make_menu(menu_t *menu, win_t *win, call_all_t *call, const sfView *view)
{
    sfRenderWindow_setView(win->win->win, view);
    draw_menu(menu, win);
    loop_menu(win, menu, call);
}
