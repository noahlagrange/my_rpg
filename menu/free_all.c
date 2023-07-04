/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** free_all
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void free_all(menu_t *menu, win_t *win)
{
    free(menu);
    free(win);
}
