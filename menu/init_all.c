/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init_all
*/

#include "../include/menu.h"
#include "../include/npc.h"
#include "../include/player_move.h"
#include "../include/struct.h"
#include "../include/my.h"

char *init_about(void)
{
    char *str = NULL;
    str = my_strdup("     Bienvenue dans le futur Tek 1,\n \
    nous vous avons amene ici parce que nous savons que vous ne pouvez pas\n \
    vous offrir un pc gamer pour votre premiere annee a epitech.\n \
    Nous vous demandons donc de tuer des gens pour recuperer leur argent\n \
    afin que vous puissiez acheter votre PC gamer.\n \
    Appuyer sur Echap pour retourner au menu");
    return str;
}

char *init_how_to_play(void)
{
    char *str = NULL;
    str = my_strdup("     Utilisez ZQSD pour vous deplacer\n \
    Utilisez A pour attaquer au corps a corps\n \
    Utilisez E pour interagir avec le gobelin\n \
    Utilisez P pour tirer avec votre arme\n \
    Utilisez la touche Echap pour ouvrir le menu du jeu\n \
    Vos degats de corps a corps sont bases sur votre force,\n \
    qui augmente avec votre niveau.\n \
    Pour sauvegarder, cliquez sur le bouton SAVE dans le menu pause\n \
    Appuyer sur Echap pour retourner au menu.");
    return str;
}

void make_all(menu_t *menu)
{
    music_in_game_menu(menu->sound);
    main_title("NeuroCity", menu->title);
    about_title("HowToPlay", menu->title);
    about_main(menu->how_to_play, menu->text);
    how_title("About", menu->title);
    how_main(menu->about, menu->text);
    create_back("assets/img/7.png", menu->back);
    create_back_settings("assets/img/clem.jpg", menu->back);
}

void init_menu(menu_t *menu, win_t *win)
{
    menu->back = malloc(sizeof(background_t));
    menu->but = malloc(sizeof(buttons_t));
    menu->sound = malloc(sizeof(sound_t));
    menu->text = malloc(sizeof(tex_t));
    menu->title = malloc(sizeof(title_t));
    win->win = malloc(sizeof(window_t));
    menu->sound->music = sfMusic_createFromFile("assets/sound/2.ogg");
    menu->sys = malloc(sizeof(system_t));
    win->game_states = 0;
    menu->sys->current_states = MENU;
    menu->sys->current_states_settings = BASE;
    menu->sys->current_states_pause = NORMAL;
    menu->about = init_about();
    menu->how_to_play = init_how_to_play();
    make_all(menu);
}
