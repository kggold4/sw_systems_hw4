# variables
CC = gcc
WGC = -Wall -g -c

# main command
all: frequency

frequency: trie.o frequency.o
	$(CC) -Wall trie.o frequency.o -o frequency

frequency.o: frequency.c frequency.h
	$(CC) $(WGC) frequency.c

trie.o: trie.c
	$(CC) $(WGC) trie.c trie.h

.PHONY: clean all

# removing all .o, .out, frequency (exeute) file
clean:
	rm -f *.o *.out *.a *.so *.gch main frequency