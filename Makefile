##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rf

NAME	=	my_rpg

CFLAGS	+=	-W -Wall -Wextra -Wdeprecated-declarations -Iinclude

LDFLAGS	+=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

SRC	=	./game/window/create_window.c \
		./game/window/analyse_events.c \
		./game/window/vector_creation.c \
		./game/window/declare_map.c \
		./game/menu/create_sprite_menu.c \
		./game/menu/create_sprite_menu_2.c \
		./game/menu/menu.c \
		./game/menu/menu_button.c \
		./game/utili/my_getnbr.c \
		./game/utili/my_puterror.c \
		./game/utili/my_strlen.c \
		./game/utili/my_strtok.c \
		./game/in_game/create_sprite_game.c \
		./game/in_game/create_sprite_game_2.c \
		./game/in_game/mouve_perso.c \
		./game/in_game/gest_zombie/anim_zombie.c \
		./game/in_game/gest_zombie/fight.c \
		./game/in_game/button_ingame/create_sprite_button_ingame.c \
		./game/in_game/gest_zombie/create_sprite_fight_house.c \
		./game/in_game/gest_zombie/create_sprite_fight_boss.c \
		./game/in_game/pause_in_game/button_pause_in_game.c \
		./game/in_game/pause_in_game/pause_in_game.c \
		./game/in_game/gest_zombie/anim_perso.c \
		./game/in_game/button_ingame/gest_buttonfight.c \
		./inventory/creator/inventory_init.c \
		./inventory/render/inventory_render.c \
		./inventory/update/inventory_update.c \
		./scenes/scene.c \
		./scenes/first_fight.c \
		./scenes/second_fight.c \
		./scenes/fight_boss.c \
		./attack.c \
		./stats.c \
		./collision.c \
		main.c \
		destroy.c \
		destroy2.c

OBJ	=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -Wdeprecated-declarations

valgrind:
	$(CC) -g -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re all clean fclean
