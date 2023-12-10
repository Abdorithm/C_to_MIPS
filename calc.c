#include "headers/main.h"

/**
 * do_priority - do operation with correct priority
 * @opst: struct of operations
 * @head: head of linked list
 *
 * Return: result
 */
int do_priority(instruction_t opst[], expr_t *head)
{
	expr_t *tmp = head;
	int i = 0, value = 0;

	while (opst[i].opcode != NULL)
	{
		tmp = head;
		while (tmp)
		{
			if (strcmp(tmp->data, opst[i].opcode) == 0)
			{
				value = opst[i].f(atoi(tmp->prev->data), atoi(tmp->next->data));

				tmp->data = tostring(value); 
				if (tmp->prev->prev)
				{
					tmp->prev = tmp->prev->prev;
					free_node(tmp->prev->next);
					tmp->prev->next = tmp;
				}
				else
			{
					free_node(tmp->prev);
					tmp->prev = NULL;
					head = tmp;
				}

				if (tmp->next->next)
				{
					tmp->next = tmp->next->next;
					free_node(tmp->next->prev);
					tmp->next->prev = tmp;
				}
				else
			{
					free_node(tmp->next);
					tmp->next = NULL;
				}
			}
			tmp = tmp->next;
		} /* print_list(head); */

		i++;
	}
	return (value);
}

/**
 * calc - calculate the value of rightside
 * @rightside: the value that have to be in register
 *
 * Return: calculated value
 * Description: ...
 */
int calc(char *rightside)
{
	instruction_t opst[] = {
		{"<<", shift_left},
		{">>", shift_right},
		{"%", mod},
		{"*", mul},
		{"/", divs},
		{"+", add},
		{"-", sub},
		{NULL, NULL}
	};

	char **separateline = get_argv(rightside);
	int value = 0;
	expr_t *head = fill_linked_list(separateline);

	free_2d(separateline); /* we don't need it anymore! */
	value = do_priority(opst, head);
	print_list(head);
	free_list(head);

	return (value);
}

