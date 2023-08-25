CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_putchar.c \
		  ft_putstr.c \
		  ft_strcmp.c \
		  ft_hexdump_core.c \
		  ft_hexdump_formatter.c \
		  ft_hexdump_hex.c \
		  ft_hexdump_ascii.c \
		  ft_hexdump.c
OUTPUT = ft_hexdump

.PHONY: all fclean clean

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

$(SOURCES):

fclean: clean
	rm -f $(OUTPUT)

clean:
