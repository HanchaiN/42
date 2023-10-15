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

INC_DIR = includes
INC = \
	ft_printf.h \
	$(INC_DIR)/printf_conversion.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I $(INC_DIR) -I $(LIBFT_DIR)

AR = ar
ARFLAGS = -crs

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SRC) $(INC):

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
