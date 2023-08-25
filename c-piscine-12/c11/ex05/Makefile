CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_atoi.c \
		  ft_do_op.c \
		  ft_operators.c \
		  ft_putchar.c \
		  ft_putnbr.c \
		  ft_putstr.c \
		  ft_strcmp.c
OUTPUT = do-op

.PHONY: all fclean clean
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

$(SOURCES):

fclean: clean
	rm -f $(OUTPUT)

clean:
