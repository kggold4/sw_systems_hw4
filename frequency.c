#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_LETTERS ((int)26)

// boolean enum
typedef enum {FALSE=0, TRUE=1} boolean;

// struct of a node
typedef struct node {

    // each node save a leter
    char letter;

    // counter
    long unsigned int count;

    // pointer to children array
    struct node* children[NUM_LETTERS];
} node;

void input() {
    
}

// main function
int main() {

    in = *boolean[NUM_LETTERS];
    
    return 0;
}