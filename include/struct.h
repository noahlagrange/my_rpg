/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** struct
*/

#include <SFML/Window.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "menu.h"
#include "player_move.h"
#include "npc.h"
#include "my.h"
#include "game_over.h"

#pragma once

#define MAIN_POINTER void (*action)(win_t *win, menu_t *menu, call_all_t *call)
#define S_POINT void (*action2)(menu_t *menu, system_t *sys, sound_t *music)
#define P_POINT void (*action3)(menu_t *menu, win_t *win, perso_t *perso)

typedef struct init_s {
    win_t *win;
    buttons_t *buttons;
}init_t;

typedef struct all_npc_s {
    zone_npc_t **rec;
    npc_img_t **npc;
    sfClock *clock;
    sfTime time;
    float delta;
}all_npc_t;

typedef struct call_all_s {
    player_move_t **player;
    clock_move_t *clock;
    init_t *init;
    all_npc_t *npc;
    npc_pos_t **npc_pos;
    info_t *info;
    int dir;
    loop_t *loop;
    game_over_t *game_over;
}call_all_t;

struct buttons_s {;
    int click;
    sfFloatRect box;
    sfRectangleShape *rec;
    sfSound *sound;
    sfBool is_clicked;
    void (*action)(win_t *win, menu_t *menu, call_all_t *call);
    void (*action2)(menu_t *menu, system_t *sys, sound_t *music);
    void (*action3)(menu_t *menu, win_t *win, perso_t *perso);
    enum GameStates target_state_game;
    enum SettingsStates target_state_settings;
    enum DiffStates target_state_game_pause;
};

typedef struct func_s {
    enum GameStates current_states;
    void (*action)(win_t *win, menu_t *menu, call_all_t *call);
} func_t;

typedef struct sett_s {
    enum SettingsStates current_states;
    void (*action2)(menu_t *menu, system_t *sys, sound_t *music);
} sett_t;

typedef struct pause_s {
    enum DiffStates current_states;
    void (*action3)(menu_t *menu, win_t *win, perso_t *perso);
} pause_t;

call_all_t *init_npc(call_all_t *call);
void event(win_t *win, coll_t **col, call_all_t *call);
void game_loop(init_t *init, buttons_t **but, tex_t **text, call_all_t *call);
void close_evt(win_t *win, sfEvent event);
void make_exp(call_all_t *call, perso_t *perso);

void move_npc(call_all_t *call, win_t *win);
void move_second_npc(call_all_t *call, win_t *win);
void move_third_npc(call_all_t *call, win_t *win);
void move_fifth_npc(call_all_t *call, win_t *win);;
void create_npc(call_all_t *call);
void create_second_npc(call_all_t *call);
void create_third_npc(call_all_t *call);
void create_fifth_npc(call_all_t *call);
void zone_npc(call_all_t *call);
void pattern_first_npc(call_all_t *call, win_t *win);
void pattern_second_npc(call_all_t *call, win_t *win);
void pattern_third_npc(call_all_t *call, win_t *win);
void pattern_fifth_npc(call_all_t *call, win_t *win);
void animated_npc(call_all_t *call, int nb, float x, float max);
void animated_second_npc(call_all_t *call, int nb);

void move_player(call_all_t *call, win_t *win, coll_t **col);
void move_left(call_all_t *call, win_t *win, coll_t **col);
void move_right(call_all_t *call, win_t *win, coll_t **col);
void move_fwd(call_all_t *call, win_t *win, coll_t **col);
void move_bwd(call_all_t *call, win_t *win, coll_t **col);
void init_clock(call_all_t *call);
sfSprite *create_player(call_all_t *call, ...);
void init_player(call_all_t *call);
void launch_create(call_all_t *call);
void draw_player_and_hitbox(call_all_t *call, win_t *win);
void animate_player(call_all_t *call);
void take_damage(call_all_t *call);

int block_up(call_all_t *call, coll_t **col);
int block_dw(call_all_t *call, coll_t **col);
int block_lf(call_all_t *call, coll_t **col);
int block_rg(call_all_t *call, coll_t **col);
void set_the_clocl(call_all_t *call);

shot_t *shot_all(shot_t *shot, coll_t **col, sfRenderWindow *win);
void get_item(item_t *ite, call_all_t *call, win_t *init, perso_t *per);
sfSprite *shot_deg(call_all_t *call, sfSprite *spri, loop_t *loop);
void cac_deg(call_all_t *call, attack_t *att, perso_t *per);

attack_t *attack_all(sfRenderWindow *win, int pau,
colum_t **clo, attack_t *att);
void draw_ver(coll_t **col, vertex_t *ver, call_all_t *call, win_t *win);
int activ(call_all_t *call, win_t *win, int pause, attack_t *att);

// Fonctions_pointers_for_menu
void wait1(win_t *win, menu_t *menu, call_all_t *call);
void wait2(win_t *win, menu_t *menu, call_all_t *call);
void fonc_setting(win_t *win, menu_t *menu, call_all_t *call);

buttons_t *set_but(int x, int y, enum GameStates states, MAIN_POINTER);
buttons_t *set_but_settings(int x, int y, enum SettingsStates states, S_POINT);

void start_at(attack_t *mc, win_t *win, sfSprite *sipre, int dir);
int manage_states(menu_t *menu);
void window_loop(menu_t *menu, win_t *win, call_all_t *call, sound_t *music);
void exit_game(win_t *win, menu_t *menu, call_all_t *call);
void menu_states(win_t *win, menu_t *menu, call_all_t *call);
void loop_menu(win_t *win, menu_t *menu, call_all_t *call);
void init_all_game(call_all_t *call);
loop_t *init_game(void);
void make_menu(menu_t *menu, win_t *win, call_all_t *call, const sfView *view);
void make_play(call_all_t *call, win_t *win, world_t *world, menu_t *menu);
void event_game(win_t *win, call_all_t *call, loop_t *loop);
void set_the_view(int pause, sfView * view, sfSprite *sprite, int state);
loop_t *make_loop(win_t *win);
void cond_pause(loop_t *loop, call_all_t *call, win_t *win, world_t *world);
void resume_game(menu_t *menu, win_t *win, perso_t *perso);
void save_game(menu_t *menu, win_t *win, perso_t *perso);
void menu_return(menu_t *menu, win_t *win, perso_t *perso);
void pause_states(menu_t *menu, win_t *win, system_t *sys, perso_t *perso);
buttons_t *set_but_pause(int x, int y, enum DiffStates states, P_POINT);
tex_t *but_text_pause(char *str, int x, int y);
buttons_t **set_the_but_pause(void);
tex_t **set_the_text_pause(void);
void but_for_pause_draw(buttons_t **but_set, sfRenderWindow *win);
void text_for_pause_draw(tex_t **text_set, sfRenderWindow *win);
void draw_pause(menu_t *menu, win_t *win);
void loop_pause(system_t *sys, win_t *win, menu_t *menu, perso_t *perso);
void make_pause(system_t *sys, menu_t *menu, win_t *win, loop_t *loop);
void exp_gain(call_all_t *call, perso_t *perso);

void get_default_perso(loop_t *loop, char *path);
void change_pause_state(menu_t *menu, win_t *win);

void create_game_over_txt(call_all_t *call);
void display_txt_game_over(win_t *win, call_all_t *call, menu_t *menu);
void create_game_over(call_all_t *call);
void dezoom_view(win_t *win, call_all_t *call);
void call_dezoom(win_t *win, call_all_t *call);

void back_menu(call_all_t *call, win_t *win, menu_t *menu);
void win_game(call_all_t *call, win_t *win);
void reset_game(call_all_t *call);
void now(win_t *win, menu_t *menu, call_all_t *call);
void make_about(menu_t *menu, win_t *win);

void draw_npc(int dir, call_all_t *call, win_t *win, int ind);
void key_event2(menu_t *menu, win_t *win);
