NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/ft_dict.c \
		  srcs/core/ft_get_value.c \
		  srcs/core/ft_put_value.c \
		  srcs/locales/jp/ft_dict_jp.c
INCLUDE_DIR = includes/
LIBS = libs/libft/libft.a \
	   libs/libft_buffer/libft_buffer.a

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(SOURCES) $(LIBS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(SOURCES):

$(LIBS):
	$(MAKE) -C $(dir $@)

re: fclean all

fclean: clean
	for lib in $(LIBS); do \
		$(MAKE) -C $$(dirname $$lib) fclean; \
	done
	rm -f $(NAME)

clean:
	for lib in $(LIBS); do \
		$(MAKE) -C $$(dirname $$lib) clean; \
	done
