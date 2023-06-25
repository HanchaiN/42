include en.mk
NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/ft_dict.c \
		  srcs/core/ft_get_value.c \
		  srcs/core/ft_put_value.c \
		  srcs/core/ft_parse_entry.c \
		  srcs/core/ft_free_entry.c \
		  srcs/core/ft_parse_number.c \
		  srcs/fileio/ft_read_line.c \
		  $(LOCALE_SOURCES)
INCLUDE_DIR = includes/
LIBS = libs/libft/libft.a \
	   libs/libft_buffer/libft_buffer.a
DEFAULT_DICT = ./numbers.en.dict

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
