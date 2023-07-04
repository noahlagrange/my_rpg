/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_get_map
*/
#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

map_t *set_map(map_t *rest, char *buf)
{
    rest->x = 0;
    rest->y = 0;
    for (int i = 0; buf[i] != '\n'; i++)
        if (buf[i] == ',')
            rest->x += 1;
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n')
            rest->y += 1;
    rest->map = malloc(sizeof(int) * (my_strlen(buf) + 1));
    int vil = 0;
    int i = 0;
    for (; buf[i] != '\0'; i++) {
        if (buf[i] != '\n' && buf[i] != ',') {
            rest->map[vil] = my_getnbr(buf + i);
            vil += 1;
        }
        while (buf[i] >= '0' && buf[i] <= '9')
            i++;
    }
    return rest;
}

map_t *getmap(void)
{
    map_t *rest = malloc(sizeof(map_t));
    char *buf = NULL;
    struct stat meta;

    stat("stock_variables/map", &meta);
    if (stat("stock_variables/map", &meta) == -1)
        return rest;
    buf = malloc(sizeof(char) * meta.st_size);
    int fd = open("stock_variables/map", O_RDONLY);
    read(fd, buf, meta.st_size);
    rest = set_map(rest, buf);
    return rest;
}
