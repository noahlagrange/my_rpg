/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_npc
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void create_fifth_npc(call_all_t *call)
{
    call->npc->npc[DOWN + 12] = create_sprite("assets/charac/robot_down.png"
    ,(sfVector2f) {650, 100}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[UP + 12] = create_sprite("assets/charac/robot_up.png",
    (sfVector2f) {650, 100}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[LEFT + 12] = create_sprite("assets/charac/robot_left.png"
    ,(sfVector2f) {650, 100}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[RIGHT + 12] = create_sprite("assets/charac/robot_right.png",
    (sfVector2f) {650, 100}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
}

void create_third_npc(call_all_t *call)
{
    call->npc->npc[DOWN + 8] = create_sprite("assets/charac/mafia_down.png"
    ,(sfVector2f) {650, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 32});
    call->npc->npc[UP + 8] = create_sprite("assets/charac/mafia_up.png",
    (sfVector2f) {650, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 31});
    call->npc->npc[LEFT + 8] = create_sprite("assets/charac/mafia_left.png"
    ,(sfVector2f) {650, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 32});
    call->npc->npc[RIGHT + 8] = create_sprite("assets/charac/mafia_right.png",
    (sfVector2f) {650, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 31});

    create_fifth_npc(call);
}

void create_second_npc(call_all_t *call)
{
    call->npc->npc[DOWN + 4] = create_sprite("assets/charac/robot_down.png"
    ,(sfVector2f) {200, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[UP + 4] = create_sprite("assets/charac/robot_up.png",
    (sfVector2f) {200, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[LEFT + 4] = create_sprite("assets/charac/robot_left.png"
    ,(sfVector2f) {200, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});
    call->npc->npc[RIGHT + 4] = create_sprite("assets/charac/robot_right.png",
    (sfVector2f) {200, 600}, (sfVector2f) {1.5, 1.5},
    (sfIntRect) {0, 0, 32, 34});

    create_third_npc(call);
}

void create_npc(call_all_t *call)
{
    call->npc_pos[0]->clock = sfClock_create();
    call->npc->npc[DOWN] = create_sprite("assets/charac/npc_chauve_down.png",
    (sfVector2f) {1250, 500}, (sfVector2f) {0.2, 0.2},
    (sfIntRect) {0, 0, 233.75, 290});
    call->npc->npc[UP] = create_sprite("assets/charac/npc_chauve_up.png",
    (sfVector2f) {1250, 500}, (sfVector2f) {0.2, 0.2},
    (sfIntRect) {0, 0, 233.75, 287});
    call->npc->npc[LEFT] = create_sprite("assets/charac/npc_chauve_left.png",
    (sfVector2f) {1250, 500}, (sfVector2f) {0.2, 0.2},
    (sfIntRect) {0, 0, 233.75, 279});
    call->npc->npc[RIGHT] = create_sprite("assets/charac/npc_chauve_right.png",
    (sfVector2f) {1250, 500}, (sfVector2f) {0.2, 0.2},
    (sfIntRect) {0, 0, 233.75, 281});

    create_second_npc(call);
}

npc_img_t *create_sprite(char *str, sfVector2f pos,
sfVector2f scale, sfIntRect size)
{
    npc_img_t *img = malloc(sizeof(npc_img_t));
    img->sprite = sfSprite_create();
    img->texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(img->sprite, img->texture, sfTrue);
    sfSprite_setPosition(img->sprite, pos);
    sfSprite_setScale(img->sprite, scale);
    img->next = size;
    sfSprite_setTextureRect(img->sprite, img->next);
    img->hp = 6;
    img->dead = 0;
    img->touch = 0;
    return img;
}
