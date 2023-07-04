/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** draw_menu
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void but_draw(buttons_t **but, sfRenderWindow *win)
{
    for (int i = 0; but[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(win, but[i]->rec,NULL);
    }
}

void text_draw(tex_t **text, sfRenderWindow *win)
{
    for (int i = 0;text[i] != NULL;i++) {
        sfRenderWindow_drawText(win, text[i]->tex_menu, NULL);
    }
}

void draw_background_menu(background_t *background, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, background->sprite_menu, NULL);
}
