/*
** EPITECH PROJECT, 2023
** save
** File description:
** //////////////
*/

#include "../include/struct.h"

void write_perso(int fd, perso_t *per)
{
    write(fd, get_str_nbr(per->niv), my_strlen(get_str_nbr(per->niv)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->pv), my_strlen(get_str_nbr(per->pv)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->amors), my_strlen(get_str_nbr(per->amors)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->deg), my_strlen(get_str_nbr(per->deg)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->gold), my_strlen(get_str_nbr(per->gold)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->exp), my_strlen(get_str_nbr(per->exp)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->pomme), my_strlen(get_str_nbr(per->pomme)));
    write(fd, "\n", 1);
    write(fd, get_str_nbr(per->get_armor),
    my_strlen(get_str_nbr(per->get_armor)));
    write(fd, "\n", 1);
}

void save_perso(perso_t *per)
{
    int fd = open("assets/save/perso", O_WRONLY, O_TRUNC, O_CREAT | 666);
    if (fd < 0) {
        return;
    }
    write_perso(fd, per);
    close(fd);
}
