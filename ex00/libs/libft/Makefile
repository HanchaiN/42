NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_putchar.c \
		  ft_putstr.c \
		  ft_strlen.c \
		  ft_strdup.c
INCLUDE_DIR = ../../includes/
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(SOURCES):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
