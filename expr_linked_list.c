#include "headers/main.h"

/**
 * fill_linked_list - fill the linked list
 * with the expression.
 * @expression: the expression.
 *
 * Return: head of the list
 */
expr_t *fill_linked_list(char **expression)
{
	expr_t *head = NULL;
	expr_t *current = NULL;
	int i;

	/* Loop through the array of strings */
	for (i = 0; expression[i]; ++i)
	{
		/* Create a new node */
		expr_t *new_node = malloc(sizeof(expr_t));

		if (!new_node)
		{
			fprintf(stderr, "Error: Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}

		/* Allocate memory for the data and copy the string */
		new_node->data = strdup(expression[i]);
		if (!new_node->data)
		{
			free_list(head);
			fprintf(stderr, "Error: Memory allocation for string failed.\n");
			exit(EXIT_FAILURE);
		}

		/* Set the pointers of the node */
		new_node->prev = current;
		new_node->next = NULL;

		/* Update the next pointer of the previous node */
		if (current)
			current->next = new_node;

		/* Update the head if it's the first node */
		if (!head)
			head = new_node;

		current = new_node;
	}
	return (head);
}

/**
 * print_list - ...
 * @head: ...
 */
void print_list(expr_t *head)
{
	expr_t *current = head;

	while (current != NULL)
	{
		printf("%s", current->data);
		if (current->next)
			printf(" -> ");
		else
			printf("\n");
		current = current->next;
	}
}

/**
 * free_list - ...
 * @head: ...
 */
void free_list(expr_t *head)
{
	expr_t *current = head;
	expr_t *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free_node(temp);
	}
}

/**
  * free_node - free a single node
  * @node: the node to free
  */
void free_node(expr_t *node)
{
	if (node == NULL)
		return;
	free(node->data);
	free(node);
}
