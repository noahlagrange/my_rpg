/*
** EPITECH PROJECT, 2022
** CUT_STR_TO_ARR
** File description:
** CUT
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_str_isalphanum(char c);

char *str_line(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == '\n') {
            str[i] = '\0';
            i += 1;
        }
        i += 1;
    }
    return (str);
}

int word_count(char *str)
{
    int i = 0;
    int len = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            len += 1;
        }
        while (str[i] == '\n') {
            i += 1;
        }
        i += 1;
    }
    return (len);
}

char **cut_to_array(char const * str)
{
    int len = my_strlen(str);
    char *cpy = my_strdup(str);
    int wc = word_count(cpy);
    char **array = malloc(sizeof(char *) * (wc + 1));
    int i = 0;
    int rap = 0;
    cpy = str_line(cpy);
    while (i <= wc && len >= 0) {
        while (cpy[0] == '\0') {
            cpy = cpy + 1;
            rap += 1;
        }
        array[i] = my_strdup(cpy);
        len = len - my_strlen(cpy);
        cpy = cpy + my_strlen(cpy) + 1;
        i += 1;
    }
    array[i - 1] = NULL;
    return array;
}
