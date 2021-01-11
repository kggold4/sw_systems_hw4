#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "frequency.h"

#define NUM_LETTERS ((int)26)
#define MAX_LINE 256
#define MAX_WORD 30
#define MAX_NODES 1024

// delete double spaces in a line ("  " => " ")
void delete_double_spaces(char *line, unsigned int n) {
    int counter = 0;
    for(int i = 0; i < n; ++i) {
        if(line[i] == ' ') { counter++; }
        else { counter = 0; }
        if(counter == 2) { for(int j = i; j < n - 1; ++j) { line[j] = line[j + 1]; } }
    }
}

// getting every word separately
void get_word(char word[], unsigned int n, node *root) {
    delete_signs(word, n);
    if(strcmp(")", word) == 18) { return; }
    add(root, word);
}

// each line that the function get, separate the line to words and sent to get word
void separate_line(char line[], unsigned int n, node *root) {

    const char empty_word[MAX_LINE] = "";

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(line[i] == ' ' || line[i] == '\n' || line[i] == '\t' || line[i] == 0 ||
           line[i] == EOF || line[i] == '\0' || line[i] == '\r' || i == n - 1) {
            if(line[i + 1] == ' ' || line[i + 1] == 0) { ++i; }
            char word[i - index];
            for(int k = 0; index < i; ++index, ++k) {
                word[k] = line[index];
            }
            
            delete_signs(word, strlen(word));
            if(strlen(word) != 0) { get_word(word, strlen(word), root); }

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
        if((line[i] < 'a' || line[i] > 'z') && line[i] != ' ' && line[i] != '\t') { line[i] = line[i + 1]; }
    }
}

// make each char in the line be lower case
void lower_case(char * line, unsigned int n) {
    for(int i = 0; i < n; i++) { *(line + i) = tolower(*(line + i)); }
}

// getting all the text by lines
// and fit the text for the trie
void build(node *root, char *line, boolean order) {

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

        // delete from the line the double spaces
        delete_double_spaces(line, strlen(line));

        // separate the line to words and sent to getword function
        separate_line(line, strlen(line), root);

        ++i;

        // end of text (no more lines)
        if(line[0] == 0 || line[0] == 'r' || line[0] == EOF || line[0] == '\0' || line[0] == '\t' || i == '\0') {

            // print results by order
            if(order) { declining(root, line, 0); }
            else { increase(root, line, 0); }

            // exit loop
            break;
        }

        // after reading a line, reset the line to an empty line
        memset(line, 0, strlen(line));
        strcpy(line, empty_line);
    }
}

// main function
int main(int argc, char const *argv[]) {

    node *root = new_node();

    // malloc the line and getting the text from user
    char *line;
    line = (char*)malloc(sizeof(char) * MAX_LINE);

    // if getting 'r' as an argument
    if(argv[1] != NULL && strcmp(argv[1], "r") == 0) {
        printf("\r");
        build(root, line, FALSE);
        
    // don't get 'r' as an argument
    } else {
        printf("\r");
        build(root, line, TRUE);
    }

    // free all memory
    free_nodes(root);
    free(line);

    return 0;
}