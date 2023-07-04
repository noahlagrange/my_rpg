/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** settings_menu
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

buttons_t *set_but_settings(int x, int y, enum SettingsStates states,
S_POINT)
{
    buttons_t *col = malloc(sizeof(buttons_t));
    col->action2 = action2;
    col->rec = sfRectangleShape_create();
    col->click = 0;
    col->box = (sfFloatRect) {x, y, 300, 50};
    sfRectangleShape_setFillColor(col->rec, sfWhite);
    sfRectangleShape_setOutlineThickness(col->rec, 2.0);
    sfRectangleShape_setOutlineColor(col->rec, sfBlack);
    sfRectangleShape_setSize(col->rec, (sfVector2f) {300, 50});
    sfRectangleShape_setPosition(col->rec, (sfVector2f) {x, y});
    col->target_state_settings = states;
    but_sound(col);
    return col;
}

tex_t *but_text_settings(char *str, int x, int y)
{
    tex_t *but = malloc(sizeof(tex_t));
    sfFont *font = sfFont_createFromFile("assets/fonts/3.ttf");
    but->tex_settings = sfText_create();
    sfText_setString(but->tex_settings, str);
    sfText_setFont(but->tex_settings, font);
    sfText_setColor(but->tex_settings, sfBlue);
    sfText_setPosition(but->tex_settings, VEC2F(x, y));
    return but;
}

buttons_t **set_the_but_for_settings(void)
{
    int mid_x = middle_screen(1920, 300);
    buttons_t **but = malloc(sizeof(buttons_t) * 4);
    but[0] = set_but_settings(mid_x, 420, VOLUME_UP, but_sound_up);
    but[1] = set_but_settings(mid_x, 490, VOLUME_DOWN, but_sound_down);
    but[2] = set_but_settings(mid_x, 560, ABOUT, about);
    but[3] = NULL;
    return but;
}

tex_t **set_the_text_for_settings(void)
{
    int mid_x = middle_screen(1920, 300);
    tex_t **but = malloc(sizeof(tex_t) * 4);
    but[0] = but_text_settings("+", (mid_x + 143), 422);
    but[1] = but_text_settings("-", (mid_x + 143), 492);
    but[2] = but_text_settings("About", (mid_x + 100), 565);
    but[3] = NULL;
    return but;
}

void loop_settings(menu_t *menu, system_t *sys, sound_t *music, win_t *win)
{
    on_the_block(menu->array_but_settings, win->win->win, sys);
    for (int i = 0;menu->array_but_settings[i] != NULL;i++) {
        settings_states(menu, sys, music);
    }
}
