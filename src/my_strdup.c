/*
** EPITECH PROJECT, 2022
** MY_STRDUP
** File description:
** task01
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *copie;
    int len = my_strlen(str);
    int i = 0;

    copie = malloc(sizeof(char) * len + 1);
    while (str[i] != '\0') {
        copie[i] = str[i];
        i += 1;
    }
    copie[i] = '\0';
    return (copie);
}
