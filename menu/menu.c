/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

int main_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    win_t *win = malloc(sizeof(win_t));
    call_all_t *call = malloc(sizeof(call_all_t));
    init_menu(menu, win);
    create_win_menu(win);
    menu->array_but_menu = set_the_but_menu();
    menu->array_text_menu = set_the_text();
    menu->array_but_settings = set_the_but_for_settings();
    menu->array_text_settings = set_the_text_for_settings();
    menu->array_but_pause = set_the_but_pause();
    menu->array_text_pause = set_the_text_pause();
    window_loop(menu, win, call, menu->sound);
    sfRenderWindow_destroy(win->win->win);
    sfMusic_destroy(menu->sound->music);
    free_all(menu, win);
    return 0;
}
