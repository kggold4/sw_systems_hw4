# variables
CC = gcc
WGC = -Wall -g -c

# main command
all: frequency

frequency: frequency.o frequency.h
	$(CC) -Wall frequency.o -o frequency

frequency.o: frequency.c
	$(CC) $(WGC) frequency.c

# removing all .o, .out, isort and txtfind (exeute) files
clean:
	rm -f *.o *.out *.a *.so main frequency