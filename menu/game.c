/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** game
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void cond_loop_pause(call_all_t *call, win_t *win, world_t *world)
{
    if (call->loop->pause == 0) {
        draw_ver(call->loop->col, call->loop->ver, call, win);
        get_item(call->loop->item, call, win, call->loop->perso);
        sfRenderWindow_drawSprite(win->win->win, world->sprite, NULL);
    }
    if (call->loop->pause == 1)
        draw_pro(call->loop->profile, call->loop->perso,
        call->loop->inv, win->win->win);
    if (call->loop->pause == -1)
        sfRenderWindow_drawSprite(win->win->win, world->intro->spri, NULL);
    if (call->loop->pause == -2)
        sfRenderWindow_drawSprite(win->win->win,
        world->march_scene->spri, NULL);
}

void event_game(win_t *win, call_all_t *call, loop_t *loop)
{
    loop->pause = activ(call, win, loop->pause, loop->att);
    if (loop->shot->tir == 0 && loop->pause != 1)
        loop->shot = lanch(win->ev, call->player[call->dir]->sprt_player,
        loop->shot, call->dir);
}

void loop_game(win_t *win, call_all_t *call, world_t *world, menu_t *menu)
{
    sfRenderWindow_clear(win->win->win, sfBlack);
    cond_loop_pause(call, win, world);
    call->loop->shot = shot_all(call->loop->shot, call->loop->col,
    win->win->win);
    call->loop->att = attack_all(win->win->win, call->loop->pause,
    call->loop->clos, call->loop->att);
    animate_player(call);
    cac_deg(call, call->loop->att, call->loop->perso);
    call->loop->shot->sprite = shot_deg(call,
    call->loop->shot->sprite, call->loop);
    if (call->npc_pos[0]->delta >= 0.40f)
        sfClock_restart(call->npc_pos[0]->clock);
    exp_gain(call, call->loop->perso);
    level_up(call->loop->perso);
    take_damage(call);
    win_game(call, win);
    display_txt_game_over(win, call, menu);
}

void init_all_game(call_all_t *call)
{
    init_npc(call);
    init_player(call);
    call->clock->clock_move = sfClock_create();
    call->clock->delta = 0;
    launch_create(call);
    create_npc(call);
    create_game_over(call);
    create_game_over_txt(call);
    zone_npc(call);
}

void make_play(call_all_t *call, win_t *win, world_t *world, menu_t *menu)
{
    if (call->loop->pause != 4)
        sfRenderWindow_setView(win->win->win, call->loop->view);
    loop_game(win, call, world, menu);
}
