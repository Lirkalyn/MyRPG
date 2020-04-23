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
		src/main_game.c

OBJ		=	$(SRC:.c=.o)

CFLAGS  =       -I ./include/

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
