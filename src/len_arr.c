/*
** EPITECH PROJECT, 2023
** len arr
** File description:
** count element arr
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int len_arr(char **arr)
{
    int nb = 0;
    for (int i = 0; arr[i] != NULL; i++)
        nb += 1;
    return nb;
}
