/*
** EPITECH PROJECT, 2023
** view
** File description:
** ////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

sfRectangleShape *make_up(void)
{
    sfRectangleShape *col = NULL;
    col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(col, 5.0);
    sfRectangleShape_setOutlineColor(col, sfRed);
    sfRectangleShape_setSize(col, (sfVector2f) {1952, 32});
    sfRectangleShape_setPosition(col, (sfVector2f) {-32, -32});
    return col;
}

sfRectangleShape *make_left(void)
{
    sfRectangleShape *col = NULL;
    col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(col, 5.0);
    sfRectangleShape_setOutlineColor(col, sfGreen);
    sfRectangleShape_setSize(col, (sfVector2f) {32, 1080});
    sfRectangleShape_setPosition(col, (sfVector2f) {-32, -32});
    return col;
}

sfRectangleShape *make_down(void)
{
    sfRectangleShape *col = NULL;
    col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(col, 5.0);
    sfRectangleShape_setOutlineColor(col, sfBlue);
    sfRectangleShape_setSize(col, (sfVector2f) {1952, 32});
    sfRectangleShape_setPosition(col, (sfVector2f) {0, 1014});
    return col;
}

sfRectangleShape *make_right(void)
{
    sfRectangleShape *col = NULL;
    col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(col, 5.0);
    sfRectangleShape_setOutlineColor(col, sfYellow);
    sfRectangleShape_setSize(col, (sfVector2f) {32, 1080});
    sfRectangleShape_setPosition(col, (sfVector2f) {1920, -32});
    return col;
}

bor_t *set_bor(void)
{
    bor_t *colli = malloc(sizeof(bor_t));
    colli->up = make_up();
    colli->down = make_down();
    colli->left = make_left();
    colli->right = make_right();
    return colli;
}
