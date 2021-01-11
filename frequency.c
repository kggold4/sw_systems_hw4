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

void delete_signs(char * line, unsigned int n);
int is_upper_letter(char ch);
void get_word(char word[], unsigned int n, node *root);

int is_upper_letter(char ch) {
    if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == EOF || ch == 0) { return 0; }
    if(ch < 'a' || ch > 'z') { return 1; }
    else { return 0; }
}

// getting every word separately
void get_word(char word[], unsigned int n, node *root) {
    delete_signs(word, n);
    if(strcmp(")", word) == 18) { return; }
    // int i = n;
    // char ch = word[n - 1];
    // while(ch == ' ' || ch == 0 || ch == '\0') { ch = word[--i]; }
    // word[i] = '\0';

    //printf("word: %s\n", word);

    printf("final word: %s\n", word);
    add(root, word);
    
    // for(int j = 0; j < n; ++j) {
    //     if(word[j] != ' ') {
    //         printf("\t!%c", word[j]);
    //     }
    // }
    // word is read for use!

    //printf("line: %s", word);
    


}

// each line that the function get, separate the line to words and sent to get word
void separate_line(char line[], unsigned int n, node *root) {

    const char empty_word[MAX_LINE] = "";

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(line[i] == ' ' || line[i] == '\n' || line[i] == 0 || line[i] == EOF || line[i] == '\0' || line[i] == '\r' || i == n - 1) {
            if(line[i + 1] == ' ') { ++i; }
            char word[i - index];
            for(int k = 0; index < i; ++index, ++k) { word[k] = line[index]; }
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
        if((line[i] < 'a' || line[i] > 'z') && line[i] != ' ') { line[i] = line[i + 1]; }
    }
}

// make each char in the line be lower case
void lower_case(char * line, unsigned int n) {
    for(int i = 0; i < n; i++) { *(line + i) = tolower(*(line + i)); }
}

// getting all the text by lines
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

        // separate the line to words and sent to getword function
        separate_line(line, strlen(line), root);

        // print line for testing
        //puts(line);

        ++i;

        // end of file
        if(line[0] == 0 || line[0] == 'r' || line[0] == EOF || line[0] == '\0' || i == '\0') {
            break;
        }

        if(order) {
            increase(root, line, 0);
        } else {
            declining(root, line, 0);
        }
        

        // after reading a line, reset the line
        memset(line, 0, strlen(line));
        strcpy(line, empty_line);
    }
}

// main function
int main(int argc, char const *argv[]) {

    
    char r[] = "r";
    // char *r;
    // r = (char*)malloc(sizeof(char)*MAX_LINE);
    // r[] = "r";
    

    node *root = newNode();

    // malloc the line and getting the text from user
    char *line;
    line = (char*)malloc(sizeof(char)*MAX_LINE);

    // if getting 'r' as an argument
    if(argv[1] != NULL && strcmp(argv[1], r) == 0) {

        build(root, line, FALSE);
        
        
    // don't get 'r' as an argument
    } else {

        printf(".");
        build(root, line, TRUE);

    }
    free_all(root);
    free(line);

    return 0;
}