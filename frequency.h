#ifndef FREQUENCY_H
#define FREQUENCY_H

void delete_double_spaces(char *line, unsigned int n);
int is_upper_letter(char ch);
void delete_signs(char * line, unsigned int n);
void get_word(char word[], unsigned int n, node *root);
void lowerCase(char * string, unsigned int n);
void separate_line(char line[], unsigned int n, node *root);
void lower_case(char * line, unsigned int n);
void build(node *root, char *line, boolean order);

#endif