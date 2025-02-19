NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/push_swap.c src/ft_exit.c\
		src/parsing/parsing.c\
		src/stack/stack_init.c\
		utils/utils.c
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re