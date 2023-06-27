NAME = libft_fileio.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = ft_get_file_size.c \
		  ft_read_file.c \
		  ft_read_line.c
INCLUDE_DIR = ../../includes/
LIBS = ../libft_buffer/libft_buffer.a \
	   ../libft/libft.a
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
