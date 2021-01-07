#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26)
#define MAX_LINE 256
#define MAX_WORD 30
#define MAX_NODES 1024

void delete_signs(char * line, unsigned int n);
int is_upper_letter(char ch);

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

int is_upper_letter(char ch) {
    if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == EOF || ch == 0) {
        return 0;
    }
    if(ch < 'a' || ch > 'z') {
        return 1;
    } else {
        return 0;
    }
}

// getting every word separately
void get_word(char word[], unsigned int n) {
    delete_signs(word, n);
    if(strcmp(")", word) == 18) {
        return;
    }
    int i = n;
    char ch = word[n - 1];
    while(ch == ' ' || ch == 0 || ch == '\0') {
        ch = word[--i];
        
    }
    word[i] = '\0';
    // word is read for use!
}

// each line that the function get, separate the line to words and sent to get word
void separate_line(char line[], unsigned int n) {

    const char empty_word[MAX_LINE] = "";

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(line[i] == ' ' || line[i] == '\n' || line[i] == 0 || line[i] == EOF || line[i] == '\0' || line[i] == '\r' || i == n - 1) {
            if(line[i + 1] == ' ') { ++i; }
            char word[i - index];
            for(int k = 0; index < i; ++index, ++k) {
                word[k] = line[index];
            }
            
            delete_signs(word, strlen(word));
            if(strlen(word) != 0) {
                get_word(word, strlen(word));
            }

            // after reading a line, reset the line
            memset(word, 0, strlen(word));
            strcpy(word, empty_word);
            //word[i] = '\0';

            // after...
            index = i + 1;
        }
    }
}

// delete every sign or char that not between 'a' and 'z' or not space
void delete_signs(char * line, unsigned int n) {
    for(int i = 0; i < n; i++) {
        if((line[i] < 'a' || line[i] > 'z') && line[i] != ' ') {
            line[i] = line[i + 1];
        }
    }
}

// make each char in the line be lower case
void lower_case(char * line, unsigned int n) {
    for(int i = 0; i < n; i++) {
        *(line + i) = tolower(*(line + i));
    }
}

// getting all the text by lines
void build(boolean b, boolean d) {

    char *line;
    node *nodes;

    // malloc the line and getting the text from user
    if(b == TRUE) {
        line = (char*)malloc(sizeof(char)*MAX_LINE);
        nodes = (node*)malloc(sizeof(node)*MAX_NODES);

        // empty line for reset the line after reading using strcpy function
        const char empty_line[MAX_LINE] = "";
        char i;
        while(i != EOF && i != 'r') {

            // getting the line
            fgets(line, MAX_LINE, stdin);

            // every char in the line that are upper case make lower case
            lower_case(line, strlen(line));

            // delete every sign or char that not between 'a' and 'z' or not space
            delete_signs(line, strlen(line));

            // separate the line to words and sent to getword function
            separate_line(line, strlen(line));

            // print line for testing
            puts(line);

            ++i;

            // end of file
            if(line[0] == 0 || line[0] == 'r' || line[0] == EOF || line[0] == '\0' || i == '\0') {
                break;
            }

            // after reading a line, reset the line
            memset(line, 0, strlen(line));
            strcpy(line, empty_line);
        }

    // free memory
    } else if(b == FALSE) {
        free(line);
        free(nodes);
    }
    
}

// main function
int main(int argc, char const *argv[]) {

    char r[] = "r";

    /*
     * build(TRUE,)  - for getting the text from the user - malloc
     * build(FALSE,) - delete the text from the mermory - free
     * build(,TRUE/FALSE) - the direction of the sorting, TRUE - from low to high, FALSE - otherwise
     */

    // if getting 'r' as an argument
    if(argv[1] != NULL && strcmp(argv[1], r) == 0) {

        build(TRUE, TRUE);
        build(FALSE, TRUE);
        
    // don't get 'r' as an argument
    } else {
        build(TRUE, FALSE);
        build(FALSE, FALSE);
    }

    return 0;
}