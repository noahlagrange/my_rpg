/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** level_up
*/
#include "../include/struct.h"

void level_up(perso_t *perso)
{
    if (perso->exp == 100) {
        perso->exp = 0;
        perso->niv += 1;
        perso->deg += 3;
        perso->pv += 3;
    }
}
