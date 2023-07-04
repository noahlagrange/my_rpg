/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** struct
*/

#pragma once

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
#include "player_move.h"
#include "npc.h"
#include "my.h"

#define VEC2F(x , y) (sfVector2f){\
x, y \
}

#define VEC2I(x , y) (sfVector2i){\
x, y \
}

// Menu

enum GameStates {
    MENU,
    PLAY,
    RESUME,
    SETTINGS,
    QUIT,
    NOW,
    PAUSE
};

enum SettingsStates {
    BASE,
    VOLUME_UP,
    VOLUME_DOWN,
    ABOUT
};

enum DiffStates {
    NORMAL,
    RESUME_GAME,
    SAVE,
    LEAVE
};

typedef struct menu_s menu_t;
typedef struct win_s win_t;
typedef struct buttons_s buttons_t;

typedef struct system_s {
    enum GameStates current_states;
    enum SettingsStates current_states_settings;
    enum DiffStates current_states_pause;
} system_t;

typedef struct tex_s {
    sfText *tex_menu;
    sfText *tex_settings;
    sfText *tex_about;
    sfText *tex_how;
    sfText *tex_pause;
} tex_t;

typedef struct title_s {
    sfText *tex;
    sfText *about;
    sfText *how;
} title_t;

typedef struct background_s {
    sfSprite *sprite_menu;
    sfTexture *texture_menu;
    sfSprite *sprite_settings;
    sfTexture *texture_settings;
    sfSprite *sprite_about;
    sfTexture *texture_about;
} background_t;

typedef struct sound_s {
    int volume;
    sfMusic *music;
} sound_t;

struct menu_s {
    sound_t *sound;
    char *about;
    char *how_to_play;
    background_t *back;
    title_t *title;
    tex_t *text;
    buttons_t *but;
    buttons_t **array_but_menu;
    tex_t **array_text_menu;
    buttons_t **array_but_settings;
    tex_t **array_text_settings;
    buttons_t **array_but_pause;
    tex_t **array_text_pause;
    system_t *sys;
};

void but_draw(buttons_t **but, sfRenderWindow *win);
buttons_t **set_the_but_menu(void);
void on_the_block(buttons_t **but, sfRenderWindow *win, system_t *sys);
tex_t *but_text_menu(char *str, int x, int y);
tex_t **set_the_text(void);
void text_draw(tex_t **text, sfRenderWindow *win);
title_t *main_title(char *str, title_t *ti);
background_t *create_back(char const *path, background_t *back);
void draw_background_menu(background_t *background, sfRenderWindow *win);
void music_in_game_menu(sound_t *music);
void but_sound(buttons_t *but);
void check_clic(buttons_t *but , system_t *sys);
background_t *create_back_settings(char const *path, background_t *back);
void draw_background_settings(background_t *background, sfRenderWindow *win);
buttons_t **set_the_but_for_settings(void);
void but_sound_up(menu_t *menu, system_t *sys, sound_t *music);
void but_sound_down(menu_t *menu, system_t *sys, sound_t *music);
buttons_t **set_the_but_menu(void);
// Window

typedef struct window_menu_s {
    sfRenderWindow *win;
    sfVideoMode mode;
} window_t;

struct win_s {
    window_t *win;
    sfEvent ev;
    int game_states;
};

void draw_title(title_t *text, win_t *win);
void create_win_menu(win_t *win);

// Struct

void init_menu(menu_t *menu, win_t *win);
void close_evt_menu(window_t *win, sfEvent event);
int middle_screen(int i, int j);
int middle_but(int i, int j);
void free_all(menu_t *menu, win_t *win);
int main_menu(void);
void draw_settings(menu_t *menu, win_t *win);
void about(menu_t *menu, system_t *sys, sound_t *music);
tex_t **set_the_text_for_settings(void);
void but_for_settings_draw(buttons_t **but_set, sfRenderWindow *win);
void text_for_settings_draw(tex_t **text_set, sfRenderWindow *win);
void settings_states(menu_t *menu, system_t *sys, sound_t *music);
void loop_settings(menu_t *menu, system_t *sys, sound_t *music, win_t *win);
title_t *about_title(char *str, title_t *ti);
tex_t *about_main(char *str, tex_t *ti);
title_t *how_title(char *str, title_t *ti);
tex_t *how_main(char *str, tex_t *ti);
void make_how(menu_t *menu, win_t *win);
void make_settings(menu_t *menu, system_t *sys, sound_t *music, win_t *win);
int manage_global(menu_t *menu);
