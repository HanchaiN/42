CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_display_file.c
OUTPUT = ft_display_file

.PHONY: all fclean clean
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

$(SOURCES):

fclean: clean
	rm -f $(OUTPUT)

clean:
