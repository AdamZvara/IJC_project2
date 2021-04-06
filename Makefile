CC=gcc
CFLAGS=-std=c99 -g -pedantic -Wall -Wextra -fPIC

LIB_SRC=$(wildcard htab*.c)
LIB_OBJ=$(patsubst %.c,%.o,$(LIB_SRC))
LIB_HEADERS=htab.h htab_private.h


.PHONY: clean

all: tail wordcount

tail: tail.o
	$(CC) $(CLFAGS) $< -o $@

wordcount: wordcount.o libhtab.a 
	$(CC) $(CFLAGS) wordcount.o -o $@ -static -L. -lhtab

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c $<

#static library
libhtab.a: $(LIB_OBJ) $(LIB_HEADERS)
	ar rcs $@ $^

#create all object files for library
htab_%.o: htab_%.c LIB_HEADERS
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o *.gch
