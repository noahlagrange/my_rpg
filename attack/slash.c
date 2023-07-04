/*
** EPITECH PROJECT, 2023
** slash
** File description:
** //////////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = 0;
    } else {
        rect->left += offset;
    }
}

attack_t *make_attack(void)
{
    attack_t *att = malloc(sizeof(attack_t));
    att->dir = 0; att->touch = 0; att->act = 0; att->sec = 0;
    att->clock = sfClock_create();
    att->texture = sfTexture_createFromFile("assets/attack/slash.png", NULL);
    att->sprite = sfSprite_create();
    att->touch = 0;
    att->rect.top = 0;
    att->rect.left = 0;
    att->rect.width = 110;
    att->rect.height = 110;
    att->act = 0;
    sfSprite_setOrigin(att->sprite, (sfVector2f){0.0, 55});
    sfSprite_setTexture(att->sprite, att->texture, sfTrue);
    sfSprite_setTextureRect(att->sprite, att->rect);
    return att;
}

void the_slash(attack_t *mc)
{
    if (mc->act == 1) {
        if (mc->dir == 0)
            sfSprite_setRotation(mc->sprite, -90.0);
        if (mc->dir == 1)
            sfSprite_setRotation(mc->sprite, 90.0);
        if (mc->dir == 2)
            sfSprite_setRotation(mc->sprite, 180.0);
        if (mc->dir == 3)
            sfSprite_setRotation(mc->sprite, 0.0);
        mc->time = sfClock_getElapsedTime(mc->clock);
        mc->sec = mc->time.microseconds / 1000000.0;
        if (mc->sec > 0.08) {
            move_rect(&mc->rect, 110, 440);
            sfSprite_setTextureRect(mc->sprite, mc->rect);
            sfClock_restart(mc->clock);
        }
    }
}

attack_t *end_slash(attack_t *mc)
{
    if (mc->act == 1) {
        if (mc->rect.left == 440) {
            mc->rect.left = 0;
            mc->act = 0;
        }
    }
    return mc;
}

void start_at(attack_t *mc, win_t *win, sfSprite *sipre, int dir)
{
    if (mc->act == 1)
        return;
    sfVector2f mou = sfSprite_getPosition(sipre);
    if (win->ev.key.code == sfKeyA && win->ev.type == sfEvtKeyPressed) {
        mc->act = 1;
        mc->dir = dir;
        mc->touch = 0;
        sfSprite_setPosition(mc->sprite, mou);
        sfClock_restart(mc->clock);
    }
}
