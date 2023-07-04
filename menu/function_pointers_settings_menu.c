/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** function_pointers_settings_menu
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void setting1(menu_t *menu, system_t *sys, sound_t *music)
{
    but_sound_up(menu, sys, music);
}

void setting2(menu_t *menu, system_t *sys, sound_t *music)
{
    but_sound_down(menu, sys, music);
}

void setting3(menu_t *menu, system_t *sys, sound_t *music)
{
    (void) menu;
    (void) sys;
    (void) music;
}

void settings_states(menu_t *menu, system_t *sys, sound_t *music)
{
    static sett_t array[] =
    {{VOLUME_UP, &setting1},
    {VOLUME_DOWN, &setting2},
    {ABOUT, &setting3},
    {0, NULL}};

    for (int i = 0;array[i].action2 != NULL;i++) {
        if (sys->current_states_settings == array[i].current_states) {
            array[i].action2(menu, sys, music);
        }
    }
}
