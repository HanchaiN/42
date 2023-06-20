CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = srcs/ft_putchar.c \
		  srcs/ft_swap.c \
		  srcs/ft_putstr.c \
		  srcs/ft_strlen.c \
		  srcs/ft_strcmp.c
INCLUDE_DIR = includes/
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = libft.a

.PHONY: all re fclean clean
all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(AR) $(ARFLAGS) $(OUTPUT) $(OBJECTS)

$(OBJECTS): $(@:.o=.c)
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(@:.o=.c)

$(SOURCES):

re: fclean all

fclean: clean
	rm -f $(OUTPUT)

clean:
	rm -f $(OBJECTS)
