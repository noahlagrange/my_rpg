/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** view
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void move_view(sfEvent event, sfView *view, sfRenderWindow *win)
{
    if (event.key.code == sfKeyUp && event.type == sfEvtKeyPressed)
        sfView_move(view, (sfVector2f) {0, -10});
    if (event.key.code == sfKeyDown && event.type == sfEvtKeyPressed)
        sfView_move(view, (sfVector2f) {0, 10});
    if (event.key.code == sfKeyRight && event.type == sfEvtKeyPressed)
        sfView_move(view, (sfVector2f) {10, 0});
    if (event.key.code == sfKeyLeft && event.type == sfEvtKeyPressed)
        sfView_move(view, (sfVector2f) {-10, 0});
    sfRenderWindow_setView(win, view);
}

void set_the_view(int pause, sfView * view, sfSprite *sprite, int state)
{
    sfVector2f mou = {0};
    if (pause == 4)
        return;
    if ((pause == 0 && state == 2) || state == 7) {
        sfView_reset(view, (sfFloatRect) {0,0, 576, 324});
        mou = sfSprite_getPosition(sprite);
        sfView_setCenter(view, mou);
    }
    if (pause != 0 || state == 1)
        sfView_reset(view, (sfFloatRect){0,0, 1920,1080});
}
