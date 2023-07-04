/*
** EPITECH PROJECT, 2023
** init struct loop
** File description:
** /////////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

loop_t *make_loop(win_t *win)
{
    loop_t *loop = malloc(sizeof(loop_t));
    loop->shot = make_sil();
    loop->arr = getmap();
    loop->ver = make_vertex(loop->arr);
    loop->inv = set_inv();
    loop->col = set_col(loop->arr);
    loop->pause = -1;
    loop->att = make_attack();
    loop->perso = get_perso();
    loop->profile = make_prof();
    loop->clos = set_colum();
    loop->item = make_item(loop->perso->pomme);
    loop->view = sfView_createFromRect((sfFloatRect){0,0,576,324});
    loop->menu = sfRenderWindow_getDefaultView(win->win->win);
    loop->world = make_world_struct();
    return loop;
}
