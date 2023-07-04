/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** player_move
*/

#ifndef PLAYER_MOVE_H_
    #define PLAYER_MOVE_H_

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
    #include <stdarg.h>

    // to know what sprite when move

    // Forward
    #define FWD 0
    // Backward
    #define BWD 1

    #define LEFT 2

    #define RIGHT 3

    typedef struct player_move_s {
        sfSprite *sprt_player;
        sfTexture *player_texture;
        sfVector2f player_pos;
        sfVector2f player_size;
        sfIntRect dim_sheet;
    }player_move_t;

    typedef struct info_s {
        int print;
        int press;
    }info_t;

    typedef struct clock_move_s {
        sfClock *clock_move;
        float delta;
        sfTime time;
    }clock_move_t;

#endif /* !PLAYER_MOVE_H_ */
