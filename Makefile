# Developed by:
# - Name: Atah Habibi
# - Username: cssc4466
# - Name: Matthew Press
# - Username: cssc4443



CC=gcc
CFLAGS=-Wall -g -std=c99
all: dsh

dsh: main.o shell.o
	$(CC) $(CFLAGS) -o dsh main.o shell.o

main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm -f *.o dsh
