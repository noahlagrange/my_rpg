/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** about_2
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

title_t *about_title(char *str, title_t *ti)
{
    int pos = middle_screen(1920, 300);
    sfFont *font = sfFont_createFromFile("assets/fonts/3.ttf");
    ti->how = sfText_create();
    sfText_setString(ti->how, str);
    sfText_setFont(ti->how, font);
    sfText_setColor(ti->how, sfWhite);
    sfText_setScale(ti->how, VEC2F(3.5, 3.5));
    sfText_setPosition(ti->how, VEC2F((pos - 150), 120));
    return ti;
}

tex_t *about_main(char *str, tex_t *ti)
{
    int pos = middle_screen(1920, 300);
    sfFont *font = sfFont_createFromFile("assets/fonts/3.ttf");
    ti->tex_how = sfText_create();
    sfText_setString(ti->tex_how, str);
    sfText_setFont(ti->tex_how, font);
    sfText_setColor(ti->tex_how, sfWhite);
    sfText_setScale(ti->tex_how, VEC2F(1, 1));
    sfText_setPosition(ti->tex_how, VEC2F((pos - 560), 500));
    return ti;
}

void draw_about_title(title_t *text, win_t *win)
{
    sfRenderWindow_drawText(win->win->win, text->how, NULL);
}

void draw_about(tex_t *text, win_t *win)
{
    sfRenderWindow_drawText(win->win->win, text->tex_how, NULL);
}

void make_about(menu_t *menu, win_t *win)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    draw_about_title(menu->title, win);
    draw_about(menu->text, win);
}
