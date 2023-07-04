/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** draw_settings
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void but_for_settings_draw(buttons_t **but_set, sfRenderWindow *win)
{
    for (int i = 0; but_set[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(win, but_set[i]->rec, NULL);
    }
}

void text_for_settings_draw(tex_t **text_set, sfRenderWindow *win)
{
    for (int i = 0;text_set[i] != NULL;i++) {
        sfRenderWindow_drawText(win, text_set[i]->tex_settings, NULL);
    }
}

void draw_background_settings(background_t *background, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, background->sprite_settings, NULL);
}

void but_for_pause_draw(buttons_t **but_set, sfRenderWindow *win)
{
    for (int i = 0; but_set[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(win, but_set[i]->rec, NULL);
    }
}

void text_for_pause_draw(tex_t **text_set, sfRenderWindow *win)
{
    for (int i = 0;text_set[i] != NULL;i++) {
        sfRenderWindow_drawText(win, text_set[i]->tex_pause, NULL);
    }
}
