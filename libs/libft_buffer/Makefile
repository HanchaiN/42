NAME = libft_buffer.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_buffer_new.c \
		  ft_buffer_free.c \
		  ft_buffer_extend.c \
		  ft_buffer_putchar.c \
		  ft_buffer_putstr.c \
		  ft_buffer_print.c
INCLUDE_DIR = ../../includes/
LIBS = ../libft/libft.a
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(LIBS):
	$(MAKE) -C $(dir $@)

$(SOURCES):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
