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
					tmp->prev = tmp->prev->prev, free_node(tmp->prev->next);
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
					tmp->next = tmp->next->next, free_node(tmp->next->prev);
					tmp->next->prev = tmp;
				}
				else
				{
					free_node(tmp->next), tmp->next = NULL;
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
int calc(notUsed char *rightside)
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

	int value = 0;
	/*
	 * i already put the line into tokens with the '=' in there
	 * fill_linked_list need to be modified to handle this.
	 */
	expr_t *head = fill_linked_list(info.curr_tokens);

	value = do_priority(opst, head);
	print_list(head);
	free_list(head);

	return (value);
}

