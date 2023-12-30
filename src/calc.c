#include "headers/main.h"

/**
 * do_priority - do operation with correct priority
 * @opst: struct of operations
 * @head: head of linked list
 *
 * Return: result
 */
expr_t *do_priority(instruction_t opst[], expr_t *head)
{
	expr_t *tmp = head, *node_value = NULL;
	int i = 0;

	while (opst[i].opcode != NULL)
	{
		tmp = head;
		while (tmp)
		{
			if (strcmp(tmp->data, opst[i].opcode) == 0)
			{
				free(tmp->data);
                                node_value = tmp;
				node_value->data = tostring(opst[i].f(atoi(tmp->prev->data), atoi(tmp->next->data)));
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
	return (node_value);
}

/**
 * calc - calculate the value of rightside
 * @rightside: the value that have to be in register
 *
 * Return: calculated value
 * Description: ...
 */
int calc(notUsed size_t line_num)
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

	expr_t* node_value = NULL;
        int value;
	/*
	 * i already put the line into tokens with the '=' in there
	 * fill_linked_list need to be modified to handle this.
	 */
	expr_t *head = fill_linked_list(info.all_lines[line_num]->tokens);

	node_value = do_priority(opst, head);
        if (node_value)
                value = atoi(node_value->data);

	print_list(head);
	free_list(head);

	return (value);
}

