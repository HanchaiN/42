NAME = libftprintf.a
SRC = \
	conversion/conversion_c.c \
	conversion/conversion_s.c \
	conversion/conversion_p.c \
	conversion/conversion_d.c \
	conversion/conversion_i.c \
	conversion/conversion_u.c \
	conversion/conversion_x_lower.c \
	conversion/conversion_x_upper.c \
	conversion/conversion.c \
	ft_printf.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = includes
INC = \
	ft_printf.h \
	$(INC_DIR)/printf_conversion.h \
	$(LIBFT_DIR)/libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I $(INC_DIR) -I $(LIBFT_DIR)

AR = ar
ARFLAGS = -crs

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC) $(INC):

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
