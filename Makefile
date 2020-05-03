##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY	:	$(NAME) clean fclean re

NAME	=	my_rpg

SRC	=	main.c	\
		src/find.c	\
		src/main_game.c \
		src/battle/battle.c \
		src/battle/initialization.c \
		src/battle/initialization_2.c \
		src/battle/gauge_initialization.c \
		src/battle/txt_initialization.c \
		src/battle/txt_initialization_2.c \
		src/battle/player_initialization.c \
		src/battle/enem_initialization.c \
		src/display.c \
		src/error_disp.c \
		src/battle/action.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS  =       -I ./include/

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
