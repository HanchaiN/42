CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_lib.c \
		  ft_tail_core.c \
		  ft_tail_format.c \
		  ft_tail.c
OUTPUT = ft_tail

.PHONY: all fclean clean
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

$(SOURCES):

fclean: clean
	rm -f $(OUTPUT)

clean:
