/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** menu_pause_fonctions
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void resume_game(menu_t *menu, win_t *win, perso_t *perso)
{
    (void)menu;
    (void)win;
    (void)perso;
}

void save_game(menu_t *menu, win_t *win, perso_t *perso)
{
    (void)menu;
    (void)win;
    save_perso(perso);
}

void menu_return(menu_t *menu, win_t *win, perso_t *perso)
{
    (void)menu;
    (void)win;
    (void)perso;
}

void pause_states(menu_t *menu, win_t *win, system_t *sys, perso_t *perso)
{
    static pause_t array[] =
        {{RESUME_GAME, &resume_game},
        {SAVE, &save_game},
        {LEAVE, &menu_return},
        {0, NULL}};

    for (int i = 0; array[i].action3 != NULL; i++) {
        if (sys->current_states_pause == array[i].current_states) {
            array[i].action3(menu, win, perso);
        }
    }
}
