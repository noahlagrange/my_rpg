/*
** EPITECH PROJECT, 2023
** get_the_perso_info
** File description:
** info_path
*/

#include "../include/struct.h"

perso_t *get_info_perso(char *buf, perso_t *perso)
{
    char **arr = cut_to_array(buf);
    perso->pv = my_getnbr(arr[1]);
    perso->exp = my_getnbr(arr[5]);
    perso->gold = my_getnbr(arr[4]);
    perso->amors = my_getnbr(arr[2]);
    perso->niv = my_getnbr(arr[0]);
    perso->deg = my_getnbr(arr[3]);
    perso->pomme = my_getnbr(arr[6]);
    perso->get_armor = my_getnbr(arr[7]);
    return perso;
}

void get_default_perso(loop_t *loop, char *path)
{
    char *buf = NULL;
    struct stat meta;
    stat(path, &meta);
    if (stat(path, &meta) == -1)
        return;
    buf = malloc(sizeof(char) * meta.st_size);
    int fd = open(path, O_RDONLY);
    read(fd, buf, meta.st_size);
    loop->perso = get_info_perso(buf, loop->perso);
}
