/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** music
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

void music_in_game_menu(sound_t *music)
{
    music->volume = 5;
    sfMusic_play(music->music);
    sfMusic_setVolume(music->music, music->volume);
    sfMusic_setLoop(music->music, sfTrue);
}

void but_sound(buttons_t *but)
{
    char *pathname = NULL;
    pathname = "assets/sound/on_but.ogg";
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(pathname);
    but->sound = sfSound_create();
    sfSound_setVolume(but->sound, 30);
    sfSound_setBuffer(but->sound, buff);
}
