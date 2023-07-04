/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** change_states_in_game
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void change_pause_state(menu_t *menu, win_t *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->win->win);
    for (int i = 0; menu->array_but_pause[i]; i++) {
        sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(menu->array_but_pause[i]->rec);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            menu->sys->current_states_pause =
            menu->array_but_pause[i]->target_state_game_pause;
        }
    }
}

void key_event2(menu_t *menu, win_t *win)
{
    if ((menu->sys->current_states == PAUSE))
        change_pause_state(menu, win);
    if (menu->sys->current_states == MENU)
        menu->sys->current_states_settings = BASE;
    if ((menu->sys->current_states == MENU) ||
    (menu->sys->current_states == PLAY))
        menu->sys->current_states_pause = NORMAL;
}
