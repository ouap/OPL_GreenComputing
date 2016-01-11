CC = gcc
CFLAGS = -Wall -Werror -pedantic
CFLAGS += -g

all: binPack

binPack: binPack.o
	$(CC) $(CFLAGS) -o $@ $^


.o: .c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	$(RM) *.o binPack
		
