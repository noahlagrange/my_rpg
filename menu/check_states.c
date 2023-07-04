/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** states
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void on_the_block(buttons_t **but, sfRenderWindow *win, system_t *sys)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; but[i] != NULL; i++) {
        if (sfFloatRect_contains(&but[i]->box, mouse.x, mouse.y)) {
            sfRectangleShape_setOutlineThickness(but[i]->rec, 2.5);
            sfRectangleShape_setOutlineColor(but[i]->rec, sfBlue);
            check_clic(but[i], sys);
        } else {
            sfRectangleShape_setOutlineThickness(but[i]->rec, 2.0);
            sfRectangleShape_setOutlineColor(but[i]->rec, sfBlack);
            sfSound_play(but[i]->sound);
        }
    }
}

void check_clic(buttons_t *but , system_t *sys)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sys->current_states != SETTINGS) {
        sys->current_states = but->target_state_game;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sys->current_states == SETTINGS) {
        sys->current_states_settings = but->target_state_settings;
    }
}
