NAME = push_swap
SRC = $(wildcard src/push_swap/*.c)
OBJ = $(SRC:.c=.o)

NAME_BONUS = checker
SRC_BONUS = $(wildcard src/checker/*.c)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

INC_DIR = includes
INC = $(wildcard $(INC_DIR)/*.h)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(LIBFT) $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SRC) $(INC):

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all
