#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h>
#include <stdlib.h> /* */
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h>

/**
 * struct token_node_name - ...
 * @token: ...
 * @length: ..
 */
typedef struct token_node_name
{
	char *token;
	int length;
	struct token_node_name *next;
} token_node;

/*1_tokenize.c*/
token_node *tokenize(char *string, token_node **tokens);

/*2_execute.c a command with its entire path*/
int execute(token_node **head, char *environment[]);

/* 2_builtins_structure.c search for match between the first and only token */
/*                         with the builtins and execute the builtin */
int builtins_structure(token_node **tokens);

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(token_node **tokens);
} builtins;

int builtin_exit(token_node **tokens);

int builtin_env(token_node **tokens);

/*1_manage_param_list.c*/

token_node *add_token(token_node **head, char *token);

void free_tokens_list(token_node **head);

token_node *get_token_node(token_node *head_list, unsigned int index);

char *get_token_at(token_node *head_list, unsigned int index);

/* util.c */
int str_length(char *string);

char *str_duplicate(char *string);

#endif /* SHELL_H */
