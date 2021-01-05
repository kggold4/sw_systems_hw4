#include <stdio.h>
#include <ctype.h>
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

void lowerCase(char * string, unsigned int n) {
    for(int i = 0; i < n; i++) {
        printf("%c", *(string + i));
        *(string + i) = tolower(*(string + i));
    }
}

void input() {
    char string[MAX_LINE];
    char i;
    while(i < MAX_LINE) {
        fgets(string, MAX_LINE, stdin);
        ++i;

        printf("\nget %s\n", string);
        // end of text
        if(string[i] == '\0') {
            printf("\nend\n");
            break;
        }
    }
    
    printf("gets: %s\n", string);
    lowerCase(string, strlen(string));
    printf("\nstring: %s\n", string);
}

// main function
int main() {

    // *boolean[NUM_LETTERS] in;
    input();

    
    return 0;
}