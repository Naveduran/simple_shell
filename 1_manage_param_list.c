#include "shell.h"

/**
 * add_token - adds a new node at the end of a token_node list.
 *
 * @head: pointer to head of list
 * @token: string to add as a new node
 *
 * Return: list with node added
 */
token_node *add_token(token_node **head, const char *token)
{
	token_node *new_node;
	int str_len;

	if (*head)
		return (add_token(&(*head)->next, token));

	str_len = str_length((char *)token);

	/* create new node */
	new_node = malloc(sizeof(token_node));
	if (new_node == NULL)
		return (NULL);

	new_node->token = strdup(token);
	new_node->length = str_len;
	new_node->next = NULL;

	/* add new node to end of list*/
	*head = new_node;
	return (new_node);
}

/**
 * free_tokens_list - deallocate the memory of a list
 *
 * @head: pointer to head of list.
 *
 * Return: nothing
 */
void free_tokens_list(token_node *head)
{
	if (!head)
		return;

	free_tokens_list(head->next);

	if (head->token)
		free(head->token);
	free(head);
}
