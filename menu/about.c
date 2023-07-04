/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** about
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

title_t *how_title(char *str, title_t *ti)
{
    int pos = middle_screen(1920, 300);
    sfFont *font = sfFont_createFromFile("assets/fonts/2.ttf");
    ti->about = sfText_create();
    sfText_setString(ti->about, str);
    sfText_setFont(ti->about, font);
    sfText_setColor(ti->about, sfWhite);
    sfText_setScale(ti->about, VEC2F(3.5, 3.5));
    sfText_setPosition(ti->about, VEC2F((pos - 150), 120));
    return ti;
}

tex_t *how_main(char *str, tex_t *ti)
{
    int pos = middle_screen(1920, 300);
    sfFont *font = sfFont_createFromFile("assets/fonts/2.ttf");
    ti->tex_about = sfText_create();
    sfText_setString(ti->tex_about, str);
    sfText_setFont(ti->tex_about, font);
    sfText_setColor(ti->tex_about, sfWhite);
    sfText_setScale(ti->tex_about, VEC2F(1, 1));
    sfText_setPosition(ti->tex_about, VEC2F((pos - 560), 500));
    return ti;
}

void draw_how_title(title_t *text, win_t *win)
{
    sfRenderWindow_drawText(win->win->win, text->about, NULL);
}

void draw_how(tex_t *text, win_t *win)
{
    sfRenderWindow_drawText(win->win->win, text->tex_about, NULL);
}

void make_how(menu_t *menu, win_t *win)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    draw_how_title(menu->title, win);
    draw_how(menu->text, win);
}
