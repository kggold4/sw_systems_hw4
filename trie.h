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
    struct node *children[NUM_LETTERS];
} node;

// create new node
node* new_node(void);

// add word to the trie
void add(node *root, char *word);

// return true if a node have at least one children
int has_child(node *current);

// print the words in the trie data structure in increase lexicographic order
void increase(node *root, char *word, int index);

// print the words in the trie data structure in declining lexicographic order
void declining(node *root, char *word, int index);

// free the memory of all the nodes in the trie
void free_nodes(node *root);

#endif