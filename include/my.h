/*
** EPITECH PROJECT, 2023
** my.h of my_rpg
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#pragma once

typedef struct enemi_s {
    int hp;
    sfRectangleShape *rect;
    int dead;
} enemi_t;

typedef struct map_s {
    int x;
    int y;
    int *map;
} map_t;

typedef struct coll_s {
    sfRectangleShape *rect;
} coll_t;

typedef struct bor_s {
    sfRectangleShape *up;
    sfRectangleShape *down;
    sfRectangleShape *left;
    sfRectangleShape *right;
} bor_t;

typedef struct perso_s {
    int niv;
    int pv;
    int deg;
    int exp;
    int gold;
    int amors;
    int pomme;
    int get_armor;
} perso_t;

typedef struct attack_s {
    int act;
    int touch;
    sfClock *clock;
    sfTexture *texture;
    sfTime time;
    float sec;
    sfIntRect rect;
    sfSprite *sprite;
    int dir;
} attack_t;

typedef struct profile_s {
    sfFont* font;
    sfText* tpv;
    sfText* tdeg;
    sfText* niv;
    sfText* tarmor;
    sfText* texp;
    sfText* tgold;
    sfSprite *sprite;
    sfSprite *armor;
} profile_t;

typedef struct colum_s {
    sfSprite *spri;
    sfTexture *tex;
} colum_t;

typedef struct vertex_s {
    sfVertexArray *carre;
    sfRenderStates *al;
} vertex_t;

typedef struct shot_s {
    int tir;
    sfSprite *sprite;
    int dir;
    int touch;
} shot_t;

typedef struct item_s {
    sfSprite *sprite;
    int get;
} item_t;

typedef struct intro_s {
    sfSprite *spri;
    sfTexture *tex;
    sfTexture *tex2;
    int nb;
} intro_t;

typedef struct march_s {
    sfRectangleShape *rect;
    int vide;
} march_t;

typedef struct world_s {
    intro_t *end;
    intro_t *intro;
    int past;
    intro_t *march_scene;
    march_t *gobelin;
    sfSprite *sprite;
}world_t;

typedef struct info_world_s {
    int intro;
    int target1;
    int target2;
    int target3;
    int target4;
}info_world_t;

typedef struct loop_s {
    shot_t *shot;
    map_t *arr;
    vertex_t *ver;
    sfSprite *inv;
    coll_t **col;
    world_t *world;
    int pause;
    attack_t *att;
    perso_t *perso;
    profile_t *profile;
    colum_t **clos;
    item_t *item;
    sfView *view;
    const sfView *menu;
    info_world_t *info;
} loop_t;

coll_t **set_all(coll_t **arr, int *i, int *j);
char **cut_to_array(char const * str);
char **my_str_to_word_array(char const *str);
int len_arr(char **arr);
int my_getnbr(char const *str);
int my_strlen(char const *str);
coll_t **set_col(map_t *arr);
bor_t *set_bor(void);
sfVertexArray *fonc(map_t *arr);
sfRenderStates *make_state(sfTexture *text);
int openv(sfEvent e, int op);
shot_t *lanch(sfEvent e, sfSprite *sipre, shot_t *shot, int dir);
shot_t *colli(shot_t *shot, coll_t **col);
shot_t *is_miss(shot_t *shot);
shot_t *make_sil(void);
sfSprite *set_inv(void);
perso_t *get_perso(void);
char *get_str_nbr(int nb);
void print_pro(profile_t *prof, perso_t *perso);
profile_t *make_prof(void);
perso_t *get_perso(void);
perso_t *make_perso(char *buff);
void draw_pro(profile_t *pro, perso_t *per, sfSprite *inv, sfRenderWindow *win);
colum_t **set_colum(void);
vertex_t *make_vertex(map_t *arr);
attack_t *end_slash(attack_t *mc);
void the_slash(attack_t *mc);
attack_t *make_attack(void);

enemi_t *make_ene(void);
map_t *getmap(void);
item_t *make_item(int get);
void save_perso(perso_t *per);
int intro(sfRenderWindow *win, int pause, intro_t *intro);
intro_t *make_intro(void);
sfSprite *set_armor(void);
march_t *make_march(void);
int open_mar(sfSprite *sipre, march_t *march, int pause, perso_t *perso);
int march(sfRenderWindow *win, int pause, intro_t *intro, perso_t *perso);
intro_t *make_march_scene(void);
world_t *make_world_struct(void);
void level_up(perso_t *perso);
char *my_strdup(char const *str);
