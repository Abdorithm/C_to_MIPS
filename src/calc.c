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
 * @line_num: the number of the line
 *
 * Return: number of next line to be executed
 */
int calc(notUsed size_t line_num)
{
    int value, i;
    char *last_temp = NULL, *load_type = NULL;
	instruction_t opst[] = {
		{"<", shift_left},
		{">", shift_right},
		{"%", mod},
        {"/", divs},
		{"*", mul},
        {"-", sub},
		{"+", add},
		{NULL, NULL}
	};

	expr_t* node_value = NULL;
	/* fill the tokens in a doubly linked list */
	expr_t *head = fill_linked_list(info.all_lines[line_num]->tokens);
	node_value = do_priority(opst, head);
    if (node_value)
        value = atoi(node_value->data);
    for (i = 2; i < 10 && info.reg_t[i].var != NULL; i++)
    {
        info.reg_t[i].var = NULL, info.reg_t[i].value = 0;
        last_temp = info.reg_t[i].name;
    }
    load_type = last_temp == NULL ? "li" : "lw";
	for (i = 0; i < 8; i++)
	{
		if (info.reg_s[i].var == NULL)
        {
            info.reg_s[i].var = info.all_lines[line_num]->tokens[1];
            info.reg_s[i].value = last_temp ? value : atoi(info.all_lines[line_num]->tokens[3]);
            printf("%s, %s, (%s)\n\n", load_type, info.reg_s[i].name,
                    last_temp == NULL ? info.all_lines[line_num]->tokens[3] : last_temp);
            break;
        }
	}
	free_list(head);
	return (line_num + 1);
}
