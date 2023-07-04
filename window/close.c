/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** close
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void close_evt(win_t *win, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win->win);
    }
}
