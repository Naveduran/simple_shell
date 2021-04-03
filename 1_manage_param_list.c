#include "shell.h"

/**
 * add_token - adds a new node at the end of a token_node list.
 *
 * @head: pointer to head of list
 * @token: string to add as a new node
 *
 * Return: list with node added
 */
token_node *add_token(token_node **head_list, char *token)
{
	token_node *new_node;
	int token_len;

	/* if is not the end of the list */
	if (*head_list)
		return (add_token(&(*head_list)->next, token));

	token_len = str_length(token);

	/* create new node */
	new_node = malloc(sizeof(token_node));
	if (new_node == NULL)
		return (NULL);

	new_node->token = str_duplicate(token);
	new_node->length = token_len;
	new_node->next = NULL;

	/* add new node to end of list*/
	*head_list = new_node;
	return (new_node);
}

/**
 * free_tokens_list - deallocate the memory of a list
 *
 * @head: pointer to head of list.
 *
 * Return: nothing
 */
void free_tokens_list(token_node **head)
{
	if (!*head)
		return;

	free_tokens_list(&(*head)->next);

	if ((*head)->token)
		free((*head)->token);

	free(*head);
	*head = NULL;

}



/**
 * get_token_node - get the node in the index position.
 *
 * @head_list: pointer to head of list.
 * @index: index to be returned
 *
 * Return: element in index position or NULL.
 */
token_node *get_token_node(token_node *head_list, unsigned int index)
{
	if (!head_list)
		return (NULL);

	if (index == 0)
		return (head_list);
	else
		return (get_token_node(head_list->next, index - 1));
}


/**
 * get_token_node - get the node in the index position.
 *
 * @head_list: pointer to head of list.
 * @index: index to be returned
 *
 * Return: element in index position or NULL.
 */
char *get_token_at(token_node *head_list, unsigned int index)
{
	if (!head_list)
		return (NULL);

	if (index == 0)
		return (head_list->token);
	else
		return (get_token_at(head_list->next, index - 1));
}
