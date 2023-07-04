/*
** EPITECH PROJECT, 2023
** cut
** File description:
** ////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

shot_t *shot_all(shot_t *shot, coll_t **col, sfRenderWindow *win)
{
    if (shot->tir != 0) {
        shot = colli(shot, col);
        shot = is_miss(shot);
    }
    if (shot->tir != 0 && shot->touch == 0)
        sfRenderWindow_drawSprite(win, shot->sprite, NULL);
    return shot;
}

void print_colum(int pause, colum_t **clos, sfRenderWindow *win)
{
    if (pause == 0)
        for (int i = 0; clos[i] != NULL; i++)
            sfRenderWindow_drawSprite(win, clos[i]->spri, NULL);
}

attack_t *attack_all(sfRenderWindow *win, int pau, colum_t **clo, attack_t *att)
{
    the_slash(att);
    att = end_slash(att);
    if (att->act == 1)
        sfRenderWindow_drawSprite(win, att->sprite, NULL);
    print_colum(pau, clo, win);
    return att;
}

void draw_ver(coll_t **col, vertex_t *ver, call_all_t *call, win_t *win)
{
    sfRenderWindow_drawVertexArray(win->win->win, ver->carre, ver->al);
    event(win, col, call);
}

int activ(call_all_t *call, win_t *win, int pause, attack_t *att)
{
    close_evt(win, win->ev);
    pause = openv(win->ev, pause);
    start_at(att, win, call->player[call->dir]->sprt_player, call->dir);
    return pause;
}
