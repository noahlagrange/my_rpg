/*
** EPITECH PROJECT, 2023
** intro
** File description:
** ///////////////////
*/

#include "../include/struct.h"

intro_t *make_march_scene(void)
{
    intro_t *intro = malloc(sizeof(intro_t));
    intro->spri = sfSprite_create();
    intro->tex = sfTexture_createFromFile
    ("assets/cinematique/gobo.png", NULL);
    intro->tex2 = sfTexture_createFromFile
    ("assets/cinematique/gobo2.png", NULL);
    sfSprite_setScale(intro->spri, (sfVector2f){1.9, 1.3});
    sfSprite_setTexture(intro->spri, intro->tex, sfTrue);
    intro->nb = 0;
    return intro;
}

int poor(intro_t *intro, perso_t *perso)
{
    if (perso->gold < 10) {
        sfSprite_setTexture(intro->spri, intro->tex2, sfTrue);
        intro->nb = 1;
        return -2;
    }
    perso->gold -= 10;
    perso->get_armor = 1;
    perso->amors += 2;
    return 0;
}

int march(sfRenderWindow *win, int pause, intro_t *intro, perso_t *perso)
{
    intro->nb = 0;
    sfSprite_setTexture(intro->spri, intro->tex, sfTrue);
    if (pause == -2) {
        if (perso->gold < 10) {
            sfSprite_setTexture(intro->spri, intro->tex2, sfTrue);
            intro->nb = 1;
        }
        sfRenderWindow_drawSprite(win, intro->spri, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyY) && intro->nb != 0)
            pause = 0;
        if (sfKeyboard_isKeyPressed(sfKeyY) && intro->nb == 0) {
            pause = 0;
            perso->gold -= 10;
            perso->get_armor = 1;
            perso->amors += 2;;
        }
        if (sfKeyboard_isKeyPressed(sfKeyN) && intro->nb == 0)
            pause = 0;
    }
    return pause;
}

intro_t *make_intro(void)
{
    intro_t *intro = malloc(sizeof(intro_t));
    intro->spri = sfSprite_create();
    intro->tex = sfTexture_createFromFile
    ("assets/cinematique/quest.png", NULL);
    intro->tex2 = sfTexture_createFromFile
    ("assets/cinematique/quest2.png", NULL);
    sfSprite_setScale(intro->spri, (sfVector2f){1.9, 1.3});
    sfSprite_setTexture(intro->spri, intro->tex, sfTrue);
    return intro;
}

int intro(sfRenderWindow *win, int pause, intro_t *intro)
{
    sfRenderWindow_drawSprite(win, intro->spri, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyY)) {
        pause = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyN))
        sfSprite_setTexture(intro->spri, intro->tex2, sfTrue);
    return pause;
}
