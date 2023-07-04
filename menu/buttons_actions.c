/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** buttons_actions
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void exit_game(win_t *win, menu_t *menu, call_all_t *call)
{
    (void)menu;
    (void)call;
    sfRenderWindow_close(win->win->win);
}

void now(win_t *win, menu_t *menu, call_all_t *call)
{
    (void)menu;
    (void)call;
    (void)win;
}
