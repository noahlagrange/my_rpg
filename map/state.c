/*
** EPITECH PROJECT, 2023
** state
** File description:
** init
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

sfRenderStates *make_state(sfTexture *text)
{
    sfRenderStates *al = malloc(sizeof(sfRenderStates));
    al->blendMode = sfBlendAlpha;
    al->transform = sfTransform_Identity;
    al->texture = text;
    al->shader = NULL;
    return al;
}
