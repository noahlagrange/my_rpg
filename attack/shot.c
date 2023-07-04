/*
** EPITECH PROJECT, 2023
** shot
** File description:
** //////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

shot_t *make_sil(void)
{
    shot_t *shot = malloc(sizeof(shot_t));
    sfTexture *text = sfTexture_createFromFile("assets/attack/laser.png", NULL);
    sfVector2u size = sfTexture_getSize(text);
    shot->sprite = sfSprite_create();
    sfSprite_setTexture(shot->sprite, text, sfTrue);
    sfSprite_setScale(shot->sprite, (sfVector2f){0.005,0.005});
    sfSprite_setOrigin(shot->sprite, (sfVector2f) {size.x,size.y / 2});
    shot->tir = 0;
    shot->dir = 0;
    shot->touch = 0;
    return shot;
}

shot_t *lanch(sfEvent e, sfSprite *sipre, shot_t *shot, int dir)
{
    if (e.key.code == sfKeyP && e.type == sfEvtKeyPressed) {
        shot->tir = 1;
        shot->touch = 0;
        shot->dir = dir;
        sfVector2f mou = sfSprite_getPosition(sipre);
        sfSprite_setPosition(shot->sprite, mou);
        if (shot->dir == 1 || shot->dir == 0) {
            sfSprite_setRotation(shot->sprite, 90.0);
        }
        if (shot->dir == 2 || shot->dir == 3) {
            sfSprite_setRotation(shot->sprite, 0.0);
        }
    }
    return shot;
}

shot_t *colli(shot_t *shot, coll_t **col)
{
    sfVector2f fire = sfSprite_getPosition(shot->sprite);
    for (int i = 0; col[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(col[i]->rect);
        if (sfFloatRect_contains(&rect, fire.x, fire.y)) {
            shot->tir = 0;
            shot->touch = 1;
        }
    }
    return shot;
}

shot_t *is_miss(shot_t *shot)
{
    if (shot->tir == 0)
        return shot;
    if (shot->dir == 0)
        sfSprite_move(shot->sprite, (sfVector2f){00, -10});
    if (shot->dir == 1)
        sfSprite_move(shot->sprite, (sfVector2f){00, 10});
    if (shot->dir == 2)
        sfSprite_move(shot->sprite, (sfVector2f){-10, 00});
    if (shot->dir == 3)
        sfSprite_move(shot->sprite, (sfVector2f){10, 00});
    return shot;
}
