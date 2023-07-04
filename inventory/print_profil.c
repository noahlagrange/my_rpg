/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_profil
*/
#include "../include/struct.h"

void print_pro2(profile_t *prof, perso_t *perso)
{
    sfText_setString(prof->niv, get_str_nbr(perso->niv));
    sfText_setFont(prof->niv, prof->font);
    sfText_setCharacterSize(prof->niv, 50);
    sfText_setString(prof->tdeg, get_str_nbr(perso->deg));
    sfText_setFont(prof->tdeg, prof->font);
    sfText_setCharacterSize(prof->tdeg, 50);
}

void print_pro(profile_t *prof, perso_t *perso)
{
    char *pv = get_str_nbr(perso->pv);
    char *exp = get_str_nbr(perso->exp);
    char *armor = get_str_nbr(perso->amors);
    char *gold = get_str_nbr(perso->gold);
    sfText_setString(prof->tpv, pv);
    sfText_setFont(prof->tpv, prof->font);
    sfText_setCharacterSize(prof->tpv, 50);
    sfText_setString(prof->texp, exp);
    sfText_setFont(prof->texp, prof->font);
    sfText_setCharacterSize(prof->texp, 50);
    sfText_setString(prof->tarmor, armor);
    sfText_setFont(prof->tarmor, prof->font);
    sfText_setCharacterSize(prof->tarmor, 50);
    sfText_setString(prof->tgold, gold);
    sfText_setFont(prof->tgold, prof->font);
    sfText_setCharacterSize(prof->tgold, 50);
    print_pro2(prof, perso);
}
