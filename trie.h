#ifndef TRIE_C
#define TRIE_C
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

node* getNode(void);

#endif