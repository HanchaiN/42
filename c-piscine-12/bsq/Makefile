NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/bsq.c \
		  srcs/bsq_display_grid.c \
		  srcs/bsq_find_largest_square.c \
		  srcs/bsq_free_grid.c \
		  srcs/bsq_parse_grid.c \
		  srcs/bsq_parse_header.c \
		  srcs/bsq_validation.c \
		  srcs/utils/ft_min.c
INCLUDE_DIR = includes/
INCLUDES = $(INCLUDE_DIR)/ft.h \
		   $(INCLUDE_DIR)/ft_buffer.h \
		   $(INCLUDE_DIR)/ft_fileio.h \
		   $(INCLUDE_DIR)/bsq.h
LIBS = libs/libft/libft.a \
	   libs/libft_buffer/libft_buffer.a \
	   libs/libft_fileio/libft_fileio.a \

.PHONY: all re fclean clean libs

all: libs $(NAME)

$(NAME): $(SOURCES) $(INCLUDES) $(LIBS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(SOURCES) $(LIBS)

libs:
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib); done

$(SOURCES) $(INCLUDES) $(LIBS):

re: fclean all

fclean: clean
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) fclean; done
	rm -f $(NAME)

clean:
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) clean; done
