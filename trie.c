#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define NUM_LETTERS ((int)26)

// create new node
node* newNode(void) {
    node* root = NULL;
    root = (node *)malloc(sizeof(node));
    if(root) {
        root -> count = 0;
        for(int i = 0; i < NUM_LETTERS; ++i) { root -> children[i] = NULL; }
    }
    return root;
}

void add(node *root, char *key) {
    int len = strlen(key);
    node *current_node = root;
    for(int i = 0; i < len; ++i) {
        int index = key[i] - 'a';
        if(!current_node -> children[index]) {
            current_node -> children[index] = newNode();
        }
        current_node = current_node -> children[index];
        current_node -> letter = key[i];
    }
    // mark last node as tail
    current_node -> count++;
}

// return true if a node have at least one children
int hasChild(node *current) {
    for(size_t i = 0; i < NUM_LETTERS; ++i) { if(current -> children[i]) { return TRUE; } }
    return FALSE;
}

// print the words in the trie data structure sorted by lexicographic order
void increase(node *root, char *str, int index) {
    for(int i = NUM_LETTERS - 1; i >= 0; i--) {
        if(root -> children[i]) {
            str[index] = root -> children[i] -> letter;
            increase(root -> children[i], str, index + 1);
        }
    }

    if(hasChild(root) == FALSE) {
        str[index] = '\0';
        printf("%s\t%ld\n", str, root -> count);
        return;
    }

    if(root -> count > 0) {
        str[index] = '\0';
        printf("%s\t%ld\n", str, root->count);
    }
}

// print the words in the trie data structure sorted by declining lexicographic order
void declining(node *root, char * str, int index) {
    if(hasChild(root) == FALSE) {
        str[index] = '\0';
        printf("%s\t%ld\n", str, root -> count);
        return;
    }
    
    if(root -> count > 0) {
        str[index] = '\0';
        printf("%s\t%ld\n" , str,root->count);
    }

    for (size_t i = 0; i <NUM_LETTERS; i++) {
        if(root -> children[i]) {
            str[index] = root -> children[i] -> letter;
            declining(root -> children[i], str, index + 1);
        }
    }
}

// free the memory of all the nodes in the trie
void free_all(node* root) {
    // if root is null
    if(!root) return;

    // recursive case (go to end of trie)
    for(int i = 0; i < NUM_LETTERS; i++) { free_all(root -> children[i]); }

    // base case
    free(root);
}