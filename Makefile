CC=gcc
CFLAGS=-std=c99 -g -pedantic -Wall -Wextra

SRC=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRC))

.PHONY: clean

all: wordcount clean

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $^

wordcount: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o
