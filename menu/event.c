/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

int manage_states(menu_t *menu)
{
    if (menu->sys->current_states == MENU)
        return 1;
    if (menu->sys->current_states == PLAY)
        return 2;
    if (menu->sys->current_states == SETTINGS)
        return 3;
    if (menu->sys->current_states_settings == ABOUT)
        return 4;
    if (menu->sys->current_states == PAUSE)
        return 5;
    return 0;
}

int manage_states2(menu_t *menu)
{
    if (menu->sys->current_states_pause == RESUME_GAME)
        return 6;
    if (menu->sys->current_states == RESUME)
        return 7;
    if (menu->sys->current_states_pause == SAVE)
        return 8;
    if (menu->sys->current_states == NOW)
        return 9;
    if (menu->sys->current_states_pause == LEAVE)
        return 10;
    return 0;
}

int manage_global(menu_t *menu)
{
    int states = manage_states(menu);
    if (states != 0)
        return states;
    else
        return manage_states2(menu);
    return 0;
}
