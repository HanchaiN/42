NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_atoi.c \
		  ft_calloc.c \
		  ft_isdigit.c \
		  ft_isspace.c \
		  ft_putchar_fd.c \
		  ft_putchar.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putstr_fd.c \
		  ft_putstr.c \
		  ft_strdup.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strtrim.c
INCLUDE_DIR = ../../includes/
INCLUDES = $(INCLUDE_DIR)/ft.h
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $<

$(SOURCES) $(INCLUDES):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
