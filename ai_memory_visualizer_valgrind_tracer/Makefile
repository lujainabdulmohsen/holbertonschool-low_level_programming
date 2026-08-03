CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
PROGRAMS = stack_lifetime heap_aliasing recursion

all: $(PROGRAMS)

stack_lifetime: programs/stack_lifetime.c
	$(CC) $(CFLAGS) programs/stack_lifetime.c -o stack_lifetime

heap_aliasing: programs/heap_aliasing.c
	$(CC) $(CFLAGS) programs/heap_aliasing.c -o heap_aliasing

recursion: programs/recursion.c
	$(CC) $(CFLAGS) programs/recursion.c -o recursion

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
