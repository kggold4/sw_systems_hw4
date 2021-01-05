#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26)
#define MAX_LINE 256

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

void lowerCase(char * string) {
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            printf("found: %c", string[i]);
            string[i] -= NUM_LETTERS;
        }
    }
}

void input() {
    char string[MAX_LINE];
    fgets(string, strlen(string), stdin);
    lowerCase(string);
    printf("%s\n", string);
}

// main function
int main() {

    // *boolean[NUM_LETTERS] in;
    input();

    
    return 0;
}