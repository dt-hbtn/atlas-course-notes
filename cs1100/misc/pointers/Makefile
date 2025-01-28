CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=c99
APPNAME := reverso

.PHONY := all clean

all: $(APPNAME)

clean:
	rm -f $(APPNAME)

$(APPNAME): reverse_string.c main.c
	$(CC) -o $@ $^ $(CFLAGS)
