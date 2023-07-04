/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** win
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void create_win_menu(win_t *w)
{
    w->win->mode = (sfVideoMode){1920, 1080, 32};
    w->win->win = sfRenderWindow_create(w->win->mode,
    "NeuroCity", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w->win->win, 60);
}
