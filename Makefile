##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY	:	$(NAME) clean fclean re

NAME	=	my_rpg

SRC		=	main.c 

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			gcc $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)
