/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** settings
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

background_t *create_back_settings(char const *path, background_t *back)
{
    back->sprite_settings = sfSprite_create();
    back->texture_settings = sfTexture_createFromFile(path, NULL);
    sfSprite_setScale(back->sprite_settings, VEC2F(0.80, 0.30));
    sfSprite_setTexture(back->sprite_settings, back->texture_settings, sfTrue);
    return back;
}

void make_settings(menu_t *menu, system_t *sys, sound_t *music, win_t *win)
{
    draw_settings(menu, win);
    loop_settings(menu, sys, music, win);
}
