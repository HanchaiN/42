CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_cat.c
OUTPUT = ft_cat

.PHONY: all fclean clean
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

$(SOURCES):

fclean: clean
	rm -f $(OUTPUT)

clean:
