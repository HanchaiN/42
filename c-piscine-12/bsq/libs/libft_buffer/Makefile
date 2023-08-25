NAME = libft_buffer.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_buffer_extend.c \
		  ft_buffer_free.c \
		  ft_buffer_new.c \
		  ft_buffer_print.c \
		  ft_buffer_putchar.c \
		  ft_buffer_putstr.c \
		  ft_buffer_putstrn.c \
		  ft_buffer_strdup.c
INCLUDE_DIR = ../../includes/
INCLUDES = $(INCLUDE_DIR)/ft.h \
		   $(INCLUDE_DIR)/ft_buffer.h
LIBS = ../libft/libft.a
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $<

$(SOURCES) $(INCLUDES) $(LIBS):

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
