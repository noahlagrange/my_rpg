/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** size
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

int middle_screen(int i, int j)
{
    int size = 0;
    if (i == 0 || j == 0)
        return -1;
    i = i / 2;
    j = j / 2;
    size = i - j;
    return size;
}

int middle_but(int i, int j)
{
    int size = 0;
    if (i == 0 || j == 0)
        return -1;
    j = j / 2;
    i = i + j;
    size = i;
    return size;
}
