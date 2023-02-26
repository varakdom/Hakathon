##
## EPITECH PROJECT, 2023
## test [WSL: Debian]
## File description:
## Makefile
##

SRC		=	src/main.cpp

CFLAGS	=	-std=gnu11 -Wall -Wextra -I include -lsfml-graphics -lsfml-window -lsfml-system

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-o

LIB		=	-lm -g3

NAME	=	BR 

all:	$(NAME)

$(NAME):$(OBJ)
	g++ $(OBJ) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re