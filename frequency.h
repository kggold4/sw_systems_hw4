#ifndef FREQUENCY_H
#define FREQUENCY_H

// delete double spaces in a line ("  " => " ")
void delete_double_spaces(char *line, unsigned int n);

// getting every word separately
void get_word(char word[], unsigned int n, node *root);

// each line that the function get, separate the line to words and sent to get word
void separate_line(char line[], unsigned int n, node *root);

// delete every sign or char that not between 'a' and 'z' or not space
void delete_signs(char * line, unsigned int n);

// make each char in the line be lower case
void lower_case(char * line, unsigned int n);

// getting all the text by lines
// and fit the text for the trie
void build(node *root, char *line, boolean order);

#endif