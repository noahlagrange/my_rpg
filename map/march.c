/*
** EPITECH PROJECT, 2023
** march
** File description:
** ///////////////
*/

#include "../include/struct.h"

march_t *make_march(void)
{
    march_t *mar = malloc(sizeof(march_t));
    mar->rect = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(mar->rect, 5.0);
    sfRectangleShape_setOutlineColor(mar->rect, sfRed);
    sfRectangleShape_setSize(mar->rect, (sfVector2f) {32 * 7, 32 * 3});
    sfRectangleShape_setPosition(mar->rect, (sfVector2f) {0, 3 * 32});
    mar->vide = 0;
    return mar;
}

int open_mar(sfSprite *sipre, march_t *march, int pause, perso_t *perso)
{
    if (perso->get_armor == 1)
        march->vide = 1;
    if (pause == -2 || march->vide == 1)
        return pause;
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(march->rect);
    sfVector2f mou = sfSprite_getPosition(sipre);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        if (sfFloatRect_contains(&rect, mou.x, mou.y))
            pause = -2;
    return pause;
}

void cond_pause(loop_t *loop, call_all_t *call, win_t *win, world_t *world)
{
    if (loop->pause == -1)
        loop->pause = intro(win->win->win, loop->pause, world->intro);
    loop->pause = open_mar(call->player[call->dir]->sprt_player
    , world->gobelin, loop->pause, loop->perso);
    loop->pause = march(win->win->win, loop->pause,
    world->march_scene, loop->perso);
}
