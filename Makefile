##
## EPITECH PROJECT, 2022
## bs_vertex
## File description:
## truc
##

CC 		= 	gcc

NAME = my_rpg

CFLAGS = -Wall -Wextra -Werror -W -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -g -g3 -ggdb

ATTACK = attack/cut.c \
		attack/enemi.c \
		attack/shot.c \
		attack/slash.c \

DRAW = draw/draw.c \

GAME_OVER = game_over/create_game_over.c \
			game_over/display_game_over.c \
			game_over/game_over.c \

INIT = init/init_all.c \
		init/init_loop.c \

INVENTORY = inventory/invent.c \
			inventory/set_perso.c \
			inventory/item.c          \
			inventory/print_profil.c \
			inventory/armoc.c         \
			inventory/get_perso_save.c 	\

MAP = map/set_colli.c \
		map/set_colum.c \
		map/set_get_map.c\
		map/state.c \
		map/vextex.c \
		map/intro.c         \
		map/march.c         \
		map/set_world.c 	\

MENU = menu/background_fonc.c \
		menu/but_on_screen.c \
		menu/buttons_actions.c \
		menu/check_states.c \
		menu/close.c \
		menu/draw_menu.c \
		menu/draw_settings.c \
		menu/event.c \
		menu/free_all.c \
		menu/function_pointers_main_menu.c \
		menu/function_pointers_settings_menu.c \
		menu/init_all.c \
		menu/main_menu.c \
		menu/main_title.c \
		menu/menu.c \
		menu/music.c \
		menu/settings_menu.c \
		menu/settings.c \
		menu/volume_but.c \
		menu/win_loop.c \
		menu/win.c \
		menu/game.c	\
		menu/about.c	\
		menu/menu_pause_fonctions.c	\
		menu/menu_pause.c	\
		menu/draw_menu_pause.c	\
		menu/change_states_in_game.c	\
		menu/about_2.c	\
		menu/fonc_draw.c	\

NPC = npc/create_npc.c \
		npc/move_npc.c \
		npc/move_second_npc.c \
		npc/move_third_npc.c \
		npc/move_fifth_npc.c \
		npc/pattern_first_npc.c \
		npc/pattern_second_npc.c \
		npc/pattern_third_npc.c \
		npc/pattern_fifth_npc.c \
		npc/zone_npc.c \
		npc/draw_npc.c	\


PLAYER = player/animate.c \
		player/block.c \
		player/create_player.c \
		player/move_player.c \
		player/save_perso.c    \
		player/restart_clock.c 	\
		player/take_damage.c \

LIB = src/cut_array.c \
		src/len_arr.c \
		src/my_getnbr.c \
		src/my_str_to_world_array.c \
		src/my_strdup.c \
		src/my_strlen.c \

VIEW = view/block_view.c \
		view/set_view.c \
		view/view.c \

WIN = win/win_game.c \

WINDOW = window/close.c \
		window/event.c \
		window/exp.c \
		window/level_up.c \

SRC = main.c \
		$(ATTACK) \
		$(DRAW) \
		$(GAME_OVER) \
		$(INIT) \
		$(INVENTORY) \
		$(MAP) \
		$(MENU) \
		$(NPC) \
		$(PLAYER) \
		$(LIB) \
		$(VIEW) \
		$(WIN) \
		$(WINDOW) \

OBJ = $(SRC:.c=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -lm

clean:
	find -type f -name "#*#" -delete -o \
	-type f -name "*~" -delete -o -type f -name "*.o" -delete -o \
	-type f -name "*.gc*" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
