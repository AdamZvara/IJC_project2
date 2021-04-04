CC=gcc
CFLAGS=-std=c99 -g -pedantic -Wall -Wextra

SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJS=$(patsubst %.c,%.o,$(SRC))

.PHONY: clean

all: wordcount 

$(OBJS): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -c $^

wordcount: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o *.gch
