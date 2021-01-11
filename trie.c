#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define NUM_LETTERS ((int)26)

/*
 * this trie.c file is implement a trie data structure - read more at: https://en.wikipedia.org/wiki/Trie
 */

// create new node
node* new_node(void) {
    node* root = NULL;
    root = (node *)malloc(sizeof(node));
    if(root) {
        root -> count = 0;
        for(int i = 0; i < NUM_LETTERS; ++i) { root -> children[i] = NULL; }
    }
    return root;
}

// add word to the trie
void add(node *root, char *word) {
    int len = strlen(word);
    node *current_node = root;
    for(int i = 0; i < len; ++i) {
        int index = word[i] - 'a';
        if(!current_node -> children[index]) { current_node -> children[index] = new_node(); }
        current_node = current_node -> children[index];
        current_node -> letter = word[i];
    }
    // mark last node as tail
    current_node -> count++;
}

// return true if a node have at least one children
int has_child(node *current) {
    for(size_t i = 0; i < NUM_LETTERS; ++i) { if(current -> children[i]) { return TRUE; } }
    return FALSE;
}

// print the words in the trie data structure in increase lexicographic order
void increase(node *root, char *word, int index) {
    for(int i = NUM_LETTERS - 1; i >= 0; i--) {
        if(root -> children[i]) {
            word[index] = root -> children[i] -> letter;
            increase(root -> children[i], word, index + 1);
        }
    }

    if(has_child(root) == FALSE) {
        word[index] = '\0';
        printf("%s\t%ld\n", word, root -> count);
        return;
    }

    if(root -> count > 0) {
        word[index] = '\0';
        printf("%s\t%ld\n", word, root -> count);
    }
}

// print the words in the trie data structure in declining lexicographic order
void declining(node *root, char * word, int index) {
    if(has_child(root) == FALSE) {
        word[index] = '\0';
        printf("%s\t%ld\n", word, root -> count);
        return;
    }
    
    if(root -> count > 0) {
        word[index] = '\0';
        printf("%s\t%ld\n" , word, root -> count);
    }

    for (size_t i = 0; i < NUM_LETTERS; i++) {
        if(root -> children[i]) {
            word[index] = root -> children[i] -> letter;
            declining(root -> children[i], word, index + 1);
        }
    }
}

// free the memory of all the nodes in the trie
void free_nodes(node* root) {

    // if root is null
    if(!root) return;

    // recursive to the tail of the trie
    for(int i = 0; i < NUM_LETTERS; i++) { free_nodes(root -> children[i]); }

    // base case after recursion
    free(root);
}