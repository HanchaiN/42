NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/bsq.c \
		  srcs/bsq_display_grid.c \
		  srcs/bsq_find_largest_square.c \
		  srcs/bsq_parse_header.c \
		  srcs/utils/ft_min.c \
		  srcs/validate_input.c
INCLUDE_DIR = includes/
LIBS = libs/libft_fileio/libft_fileio.a \
	   libs/libft_buffer/libft_buffer.a \
	   libs/libft/libft.a

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
