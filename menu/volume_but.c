/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** volume_but
*/
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void but_sound_up(menu_t *menu, system_t *sys, sound_t *music)
{
    (void)menu;
    (void)sys;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        music->volume++;
    if (music->volume > 100)
        music->volume = 100;
    if (music->volume < 0)
        music->volume = 0;
    sfMusic_setVolume(music->music, music->volume);
}

void but_sound_down(menu_t *menu, system_t *sys, sound_t *music)
{
    (void)menu;
    (void)sys;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        music->volume--;
    if (music->volume > 100)
        music->volume = 100;
    if (music->volume < 0)
        music->volume = 0;
    sfMusic_setVolume(music->music, music->volume);
}

void about(menu_t *menu, system_t *sys, sound_t *music)
{
    (void)sys;
    (void)music;
    (void)menu;
}
