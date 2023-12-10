#include "headers/main.h"


/**
 * malloc_failed - exit with an error message when allocation falis
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}


/**
 * free_2d - frees an array of strings form memory
 * @array: the array
 */
void free_2d(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
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

