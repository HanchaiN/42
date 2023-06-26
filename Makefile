NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/bsq.c \
		  srcs/core/bsq_find_largest_square.c \
		  srcs/fileio/ft_get_file_size.c \
		  srcs/fileio/ft_read_file.c
INCLUDE_DIR = includes/
LIBS = libs/libft/libft.a \
	   libs/libft_buffer/libft_buffer.a

.PHONY: all re fclean clean libs

all: libs $(NAME)

$(NAME): $(SOURCES) $(LIBS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

libs:
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib); done

$(SOURCES) $(LIBS):

re: fclean all

fclean: clean
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) fclean; done
	rm -f $(NAME)

clean:
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) clean; done
