#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define NUM_LETTERS ((int)26)

node* getNode(void) {
    node* root = NULL;
    root = (node *)malloc(sizeof(node));
    if(root) {
        root -> count = 0;
        for(int i = 0; i < NUM_LETTERS; ++i){
            root -> childem[i] = NULL;
        }
    }
    return root;
}

void add(node **root, char *key) {
    int len = strlen(key);
    node *current_node = *root;
    for(int i = 0; i < len; ++i) {
        int index = key[i] - 'a';
        if(!current_node -> children[index]) {
            current_node -> children[index] = getNode();
        }
        current_node = current_node -> children[index];
        current_node -> letter = key[i];
    }
    // mark last node as tail
    current_node -> count++;
}

