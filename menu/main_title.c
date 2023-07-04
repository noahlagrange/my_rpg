/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** main_title
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

title_t *main_title(char *str, title_t *ti)
{
    int pos = middle_screen(1920, 300);
    sfFont *font = sfFont_createFromFile("assets/fonts/5.ttf");
    ti->tex = sfText_create();
    sfText_setString(ti->tex, str);
    sfText_setFont(ti->tex, font);
    sfText_setColor(ti->tex, sfBlue);
    sfText_setScale(ti->tex, VEC2F(4, 4));
    sfText_setPosition(ti->tex, VEC2F((pos - 130), 120));
    return ti;
}

void draw_title(title_t *text, win_t *win)
{
    sfRenderWindow_drawText(win->win->win, text->tex, NULL);
}
