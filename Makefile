##
## EPITECH PROJECT, 2022
## PANORAMIX
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c) \
			$(wildcard dialogue/*.c) \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -g3 -lpthread

BIN		=	panoramix

all: ${OBJ}
	gcc -o ${BIN} $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(BIN)
		$(RM) $(NAME)

re: fclean all