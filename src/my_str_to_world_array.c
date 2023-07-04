/*
** EPITECH PROJECT, 2022
** MY_STR_TO_WORD_ARRAY
** File description:
** task5
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_str_isalphanum(char c);

char *str_change_word(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ',') {
            str[i] = '\0';
            i += 1;
        }
        i += 1;
    }
    return (str);
}

int get_word_count(char *str)
{
    int i = 0;
    int len = 0;
    while (str[i] != '\0') {
        if (str[i] == ',' || str[i] == '\0') {
            len += 1;
        }
        while (str[i] == ',') {
            i += 1;
        }
        i += 1;
    }
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    int len = my_strlen(str);
    char *cpy = my_strdup(str);
    int wc = get_word_count(cpy);
    char **array = malloc(sizeof(char *) * (wc + 2));
    int i = 0;
    int rap = 0;
    cpy = str_change_word(cpy);
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
    array[i] = NULL;
    return array;
}
