/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** game_over
*/

#ifndef GAME_OVER_H_
    #define GAME_OVER_H_

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

    typedef struct game_over_s {
        sfView *view;
        float zoom;
        sfText *game_over_txt;
        sfFont *font_game_over;
        sfVector2f scale_game_over;
        sfVector2f game_over_pos;
    }game_over_t;

#endif /* !GAME_OVER_H_ */
