/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** background_fonc
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

background_t *create_back(char const *path, background_t *back)
{
    back->sprite_menu = sfSprite_create();
    back->texture_menu = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(back->sprite_menu, back->texture_menu, sfTrue);
    return back;
}
