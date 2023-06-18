CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rs
SOURCES = srcs/ft_putchar.c \
		  srcs/ft_swap.c \
		  srcs/ft_putstr.c \
		  srcs/ft_strlen.c \
		  srcs/ft_strcmp.c
INCLUDES = includes/ft.h
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = libft.a
all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(AR) $(ARFLAGS) $(OUTPUT) $(OBJECTS)

$(OBJECTS):
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ $(@:.o=.c)

re: fclean all

fclean: clean
	rm -f $(OUTPUT)

clean:
	rm -f $(OBJECTS)
