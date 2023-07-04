/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** function_pointers_main_menu
*/

#include "../include/menu.h"
#include "../include/player_move.h"
#include "../include/npc.h"
#include "../include/my.h"
#include "../include/struct.h"

void wait1(win_t *win, menu_t *menu, call_all_t *call)
{
    (void)win;
    (void)menu;
    reset_game(call);
    get_default_perso(call->loop, "Default/perso");
}

void wait2(win_t *win, menu_t *menu, call_all_t *call)
{
    (void)menu;
    (void)win;
    reset_game(call);
    get_default_perso(call->loop, "assets/save/perso");
}

void fonc_setting(win_t *win, menu_t *menu, call_all_t *call)
{
    (void)win;
    (void)menu;
    (void)call;
}

void menu_states(win_t *win, menu_t *menu, call_all_t *call)
{
    static func_t array[] =
    {{PLAY, &wait1},
    {RESUME, &wait2},
    {SETTINGS, &fonc_setting},
    {QUIT, &exit_game},
    {NOW, &now},
    {0, NULL}};

    for (int i = 0;array[i].action != NULL;i++) {
        if (menu->sys->current_states == array[i].current_states) {
            array[i].action(win, menu, call);
        }
    }
}
