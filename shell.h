#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h>
#include <stdlib.h> /* */
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h>

typedef struct token_node_name{
	char *token;
	int length;
	struct token_node_name *next;
} token_node;

/*execute a command with its entire path*/
int execute(token_node **head, char *environment[]);


/*1_tokenize.c*/
token_node *tokenize(char *string, token_node **tokens);

/*1_manage_param_list.c*/

token_node *add_token(token_node **head, const char *token);
void free_tokens_list(token_node *head);


/* util.c */
int str_length(char *string);

#endif /* SHELL_H */
