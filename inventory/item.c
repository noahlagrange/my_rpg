/*
** EPITECH PROJECT, 2023
** make item
** File description:
** //////////////
*/

#include "../include/struct.h"

item_t *make_item(int get)
{
    item_t *ite = malloc(sizeof(shot_t));
    sfTexture *text = sfTexture_createFromFile("assets/object/pomme.png", NULL);
    ite->sprite = sfSprite_create();
    sfSprite_setScale(ite->sprite, (sfVector2f){0.005,0.005});
    sfSprite_setPosition(ite->sprite, (sfVector2f){300, 600});
    sfSprite_setTexture(ite->sprite, text, sfTrue);
    if (get == 0)
        ite->get = 0;
    else
        ite->get = 1;
    return ite;
}

void get_item(item_t *ite, call_all_t *call, win_t *init, perso_t *per)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(ite->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(
    call->player[call->dir]->sprt_player);
    if (sfFloatRect_intersects(&rect1, &rect2, &rect2) == sfTrue) {
        ite->get = 1;
        per->pomme = 1;
    }
    if (per->pomme == 0)
        sfRenderWindow_drawSprite(init->win->win, ite->sprite, NULL);
}
