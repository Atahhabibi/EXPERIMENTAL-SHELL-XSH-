CC=gcc
CFLAGS=-Wall -g

all: dsh

dsh: main.o shell.o
	$(CC) $(CFLAGS) -o dsh main.o shell.o

main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm -f *.o dsh
