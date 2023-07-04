/*
** EPITECH PROJECT, 2023
** invent
** File description:
** ////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

sfSprite *set_inv(void)
{
    sfTexture *text = sfTexture_createFromFile
    ("assets/inventory/inv.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setOrigin(sprite, (sfVector2f) {540,0});
    sfSprite_setPosition (sprite, (sfVector2f) {1920 / 2, 0});
    return sprite;
}

int openv(sfEvent e, int op)
{
    if (op == 0 && e.key.code == sfKeyI && e.type == sfEvtKeyPressed) {
        return 1;
    }
    if (op == 1 && e.key.code == sfKeyI && e.type == sfEvtKeyPressed) {
        return 0;
    }
    return op;
}
