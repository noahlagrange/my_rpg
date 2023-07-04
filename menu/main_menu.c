/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

buttons_t *set_but(int x, int y, enum GameStates states, MAIN_POINTER)
{
    buttons_t *col = malloc(sizeof(buttons_t));
    col->action = action;
    col->rec = sfRectangleShape_create();
    col->click = 0;
    col->box = (sfFloatRect) {x, y, 300, 50};
    sfRectangleShape_setFillColor(col->rec, sfWhite);
    sfRectangleShape_setOutlineThickness(col->rec, 2.0);
    sfRectangleShape_setOutlineColor(col->rec,  sfBlack);
    sfRectangleShape_setSize(col->rec, (sfVector2f) {300, 50});
    sfRectangleShape_setPosition(col->rec, (sfVector2f) {x, y});
    col->target_state_game = states;
    but_sound(col);
    return col;
}

tex_t *but_text_menu(char *str, int x, int y)
{
    tex_t *but = malloc(sizeof(tex_t));
    sfFont *font = sfFont_createFromFile("assets/fonts/3.ttf");
    but->tex_menu = sfText_create();
    sfText_setString(but->tex_menu, str);
    sfText_setFont(but->tex_menu, font);
    sfText_setColor(but->tex_menu, sfBlue);
    sfText_setPosition(but->tex_menu, VEC2F(x, y));
    return but;
}

buttons_t **set_the_but_menu(void)
{
    int mid_x = middle_screen(1920, 300);
    buttons_t **but = malloc(sizeof(buttons_t) * 6);
    but[0] = set_but(mid_x, 420, PLAY, wait1);
    but[1] = set_but(mid_x, 490, RESUME, wait2);
    but[2] = set_but(mid_x, 560, SETTINGS, fonc_setting);
    but[3] = set_but(mid_x, 630, QUIT, exit_game);
    but[4] = set_but(mid_x, 700, NOW, now);
    but[5] = NULL;
    return but;
}

tex_t **set_the_text(void)
{
    int mid_x = middle_screen(1920, 300);
    tex_t **but = malloc(sizeof(tex_t) * 6);
    but[0] = but_text_menu("play", (mid_x + 120), 422);
    but[1] = but_text_menu("resume", (mid_x + 100), 492);
    but[2] = but_text_menu("settings", (mid_x + 92), 562);
    but[3] = but_text_menu("quit", (mid_x + 120), 632);
    but[4] = but_text_menu("HowToPlay", (mid_x + 70), 702);
    but[5] = NULL;
    return but;
}
