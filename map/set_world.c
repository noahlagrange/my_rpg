/*
** EPITECH PROJECT, 2023
** set_the_world_truc
** File description:
** info_sur_le_monde
*/

#include "../include/struct.h"

world_t *make_world_struct(void)
{
    world_t * world = malloc(sizeof(world_t));
    world->intro = make_intro();
    world->gobelin = make_march();
    world->march_scene = make_march_scene();
    world->end = malloc(sizeof(intro_t));
    world->end->spri = sfSprite_create();
    world->end->tex = sfTexture_createFromFile
    ("assets/cinematique/end.png", NULL);
    sfSprite_setTexture(world->end->spri, world->end->tex, sfTrue);
    sfSprite_setScale(world->end->spri, (sfVector2f) {1.9, 1.3});
    sfTexture * tex = sfTexture_createFromFile(
    "assets/charac/gobelin.png", NULL);
    world->sprite = sfSprite_create();
    sfSprite_setTexture(world->sprite, tex, sfTrue);
    sfSprite_setTextureRect(world->sprite, (sfIntRect){0, 0, 138, 184});
    sfSprite_setPosition(world->sprite, VEC2F(95, 85));
    sfSprite_setScale(world->sprite, VEC2F(0.6, 0.6));
    return world;
}
