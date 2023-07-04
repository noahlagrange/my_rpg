/*
** EPITECH PROJECT, 2023
** perso
** File description:
** /////////////////
*/

#include "../include/struct.h"
#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/my.h"

perso_t *make_perso(char *buff)
{
    char **arr = cut_to_array(buff);
    perso_t *perso = malloc(sizeof(perso_t));
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

perso_t *get_perso(void)
{
    char *buf = NULL;
    struct stat meta;
    stat("stock_variables/perso", &meta);
    if (stat("stock_variables/perso", &meta) == -1)
        return NULL;
    buf = malloc(sizeof(char) * meta.st_size);
    int fd = open("stock_variables/perso", O_RDONLY);
    read(fd, buf, meta.st_size);
    perso_t *rest = make_perso(buf);
    return rest;
}

sfSprite *set_pomme(profile_t *ite)
{
    sfTexture *text = sfTexture_createFromFile("assets/object/pomme.png", NULL);
    ite->sprite = sfSprite_create();
    sfSprite_setScale(ite->sprite, (sfVector2f){0.05,0.05});
    sfSprite_setPosition(ite->sprite, (sfVector2f){1200, 800});
    sfSprite_setTexture(ite->sprite, text, sfTrue);
    return ite->sprite;
}

profile_t *make_prof(void)
{
    profile_t *prof = malloc(sizeof(profile_t));
    prof->sprite = set_pomme(prof);
    prof->armor = set_armor();
    prof->font = sfFont_createFromFile("assets/fonts/arial.ttf");
    prof->tpv = sfText_create();
    sfText_setPosition (prof->tpv, (sfVector2f) {660,650});
    prof->tarmor = sfText_create();
    sfText_setPosition (prof->tarmor, (sfVector2f) {750,915});
    prof->texp = sfText_create();
    sfText_setPosition (prof->texp, (sfVector2f) {660,550});
    prof->tgold = sfText_create();
    sfText_setPosition (prof->tgold, (sfVector2f) {1200,555});
    prof->niv = sfText_create();
    sfText_setPosition (prof->niv, (sfVector2f) {660,125});
    prof->tdeg = sfText_create();
    sfText_setPosition (prof->tdeg, (sfVector2f) {780,780});
    return prof;
}
