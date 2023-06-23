NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/ft_dict.c
INCLUDE_DIR = includes/

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(SOURCES):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
