/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-noah.lagrange
** File description:
** open_info_map
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

info_world_t *make_info(char *buf)
{
    char **arr = cut_to_array(buf);
    info_world_t *world = malloc(sizeof(info_world_t));
    world->intro = my_getnbr(arr[0]);
    world->target1 = my_getnbr(arr[1]);
    world->target2 = my_getnbr(arr[2]);
    world->target3 = my_getnbr(arr[3]);
    world->target4 = my_getnbr(arr[4]);
    return world;
}

info_world_t *get_world_info(void)
{
    char *buf = NULL;
    struct stat meta;
    stat("../Default/world", &meta);
    if (stat("../Default/world", &meta) == -1)
        return NULL;
    buf = malloc(sizeof(char) * meta.st_size);
    int fd = open("../Default/world", O_RDONLY);
    read(fd, buf, meta.st_size);
    info_world_t *rest = make_info(buf);
    return rest;
}

info_world_t *get_info_save(char *buf, info_world_t *world)
{
    char **arr = cut_to_array(buf);
    world->intro = my_getnbr(arr[0]);
    world->target1 = my_getnbr(arr[1]);
    world->target2 = my_getnbr(arr[2]);
    world->target3 = my_getnbr(arr[3]);
    world->target4 = my_getnbr(arr[4]);
    return world;
}

loop_t *get_default(loop_t *loop, char *path)
{
    char *buf = NULL;
    struct stat meta;
    stat(path, &meta);
    if (stat(path, &meta) == -1)
        return NULL;
    buf = malloc(sizeof(char) * meta.st_size);
    int fd = open(path, O_RDONLY);
    read(fd, buf, meta.st_size);
    loop->info = get_info_save(buf, loop->info);
    return loop;
}
