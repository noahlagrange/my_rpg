/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_
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
    #define DOWN 0
    #define UP 1
    #define LEFT 2
    #define RIGHT 3

    typedef struct zone_npc_s {
        sfRectangleShape *rect;
    }zone_npc_t;

    typedef struct npc_img_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect next;
        int touch;
        int dead;
        int hp;
    } npc_img_t;

    typedef struct npc_pos {
        npc_img_t *npc_img;
        sfClock *clock;
        float delta;
        sfTime time;
        int i;
        int y;
        int x;
    }npc_pos_t;

zone_npc_t *create_rectangle(sfVector2f position, sfVector2f size);
npc_img_t *create_sprite(char *str, sfVector2f pos,
sfVector2f scale, sfIntRect size);
zone_npc_t *create_rectangle(sfVector2f position, sfVector2f size);
#endif /* !NPC_H_ */
