/*
** EPITECH PROJECT, 2023
** get_armor
** File description:
** set sprite armor
*/

#include "../include/struct.h"

sfSprite *set_armor(void)
{
    sfTexture *text = sfTexture_createFromFile("assets/object/armor.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setScale(sprite, (sfVector2f){0.23,0.23});
    sfSprite_setPosition(sprite, (sfVector2f){890, 810});
    sfSprite_setTexture(sprite, text, sfTrue);
    return sprite;
}
