CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

PROGRAMS = stack_lifetime heap_aliasing recursion memory_leak use_after_free uninitialized_memory

all: $(PROGRAMS)

stack_lifetime: programs/stack_lifetime.c
	$(CC) $(CFLAGS) programs/stack_lifetime.c -o stack_lifetime

heap_aliasing: programs/heap_aliasing.c
	$(CC) $(CFLAGS) programs/heap_aliasing.c -o heap_aliasing

recursion: programs/recursion.c
	$(CC) $(CFLAGS) programs/recursion.c -o recursion

memory_leak: programs/memory_leak.c
	$(CC) $(CFLAGS) programs/memory_leak.c -o memory_leak

use_after_free: programs/use_after_free.c
	$(CC) $(CFLAGS) programs/use_after_free.c -o use_after_free

uninitialized_memory: programs/uninitialized_memory.c
	$(CC) $(CFLAGS) programs/uninitialized_memory.c -o uninitialized_memory

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
