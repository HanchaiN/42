NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_atoi.c \
		  ft_calloc.c \
		  ft_isdigit.c \
		  ft_isspace.c \
		  ft_min.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strdup.c \
		  ft_strlen.c \
		  ft_strtrim.c \
		  ft_putnbr.c
INCLUDE_DIR = ../../includes/
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(SOURCES) $(LIBS):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
