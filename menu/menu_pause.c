/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** menu_pause
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

buttons_t *set_but_pause(int x, int y, enum DiffStates states, P_POINT)
{
    buttons_t *col = malloc(sizeof(buttons_t));
    col->action3 = action3;
    col->rec = sfRectangleShape_create();
    col->click = 0;
    col->box = (sfFloatRect) {x, y, 300, 50};
    sfRectangleShape_setFillColor(col->rec, sfWhite);
    sfRectangleShape_setOutlineThickness(col->rec, 2.0);
    sfRectangleShape_setOutlineColor(col->rec,  sfBlack);
    sfRectangleShape_setSize(col->rec, (sfVector2f) {300, 50});
    sfRectangleShape_setPosition(col->rec, (sfVector2f) {x, y});
    col->target_state_game_pause = states;
    but_sound(col);
    return col;
}

tex_t *but_text_pause(char *str, int x, int y)
{
    tex_t *but = malloc(sizeof(tex_t));
    sfFont *font = sfFont_createFromFile("assets/fonts/3.ttf");
    but->tex_pause = sfText_create();
    sfText_setString(but->tex_pause, str);
    sfText_setFont(but->tex_pause, font);
    sfText_setColor(but->tex_pause, sfBlue);
    sfText_setPosition(but->tex_pause, VEC2F(x, y));
    return but;
}

buttons_t **set_the_but_pause(void)
{
    int mid_x = middle_screen(1920, 300);
    buttons_t **but = malloc(sizeof(buttons_t) * 4);
    but[0] = set_but_pause(mid_x, 420, RESUME_GAME, resume_game);
    but[1] = set_but_pause(mid_x, 490, SAVE, save_game);
    but[1]->target_state_game_pause = SAVE;
    but[2] = set_but_pause(mid_x, 560, LEAVE, menu_return);
    but[3] = NULL;
    return but;
}

tex_t **set_the_text_pause(void)
{
    int mid_x = middle_screen(1920, 300);
    tex_t **but = malloc(sizeof(tex_t) * 4);
    but[0] = but_text_pause("resume", (mid_x + 100), 422);
    but[1] = but_text_pause("save", (mid_x + 117), 492);
    but[2] = but_text_pause("quit", (mid_x + 120), 562);
    but[3] = NULL;
    return but;
}

void make_pause(system_t *sys, menu_t *menu, win_t *win, loop_t *loop)
{
    sfRenderWindow_setView(win->win->win, loop->menu);
    draw_pause(menu, win);
    loop_pause(sys, win, menu, loop->perso);
}
