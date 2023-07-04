/*
** EPITECH PROJECT, 2022
** MY_STRLEN
** File description:
** TASK03
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int my_strlen(char const *str)
{
    int len = 0;
    if (str == NULL)
        return 0;
    while (str[len] != '\0') {
        len += 1;
    }
    return (len);
}
