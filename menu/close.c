/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** close
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void close_evt_menu(window_t *win, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win);
    }
}
