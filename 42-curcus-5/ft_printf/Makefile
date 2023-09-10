NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -L ./libft -lft
AR = ar
ARFLAGS = -crsT
SOURCES = \
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
INCLUDE_DIR = .
INCLUDES = \
	$(INCLUDE_DIR)/ft_printf.h \
	$(INCLUDE_DIR)/conversion/conversion.h \
	$(INCLUDE_DIR)/libft/libft.h
LIBS = \
	libft/libft.a
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(LIBS) $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCLUDES) $(LIBS)
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $<

$(LIBS):
	$(MAKE) -C $$(dirname $@)

$(SOURCES) $(INCLUDES):

re: fclean all

fclean: clean
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) fclean; done
	rm -f $(NAME)

clean:
	for lib in $(LIBS); do $(MAKE) -C $$(dirname $$lib) clean; done
	rm -f $(OBJECTS)
