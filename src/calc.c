#include "headers/main.h"

/**
 * do_priority - do operation with correct priority
 * @opst: struct of operations
 * @head: head of linked list
 *
 * Return: result
 */
expr_t *do_priority(instruction_t opst[], expr_t *head, size_t line_num)
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
				node_value->data = tostring(opst[i].f(
					tmp->prev->data,
					tmp->next->data,
                                        line_num));
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
					free_node(tmp->next), tmp->next = NULL;
			}
			tmp = tmp->next;
		} /* print_list(head); */
		i++;
	}
	return (node_value);
}

/**
 * calc - calculate the value of rightside
 *
 * @line_num: the number of the line
 *
 * Return: number of next line to be executed
 */
size_t calc(notUsed size_t line_num)
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

        node_value = do_priority(opst, head, line_num);

        /* handle no operations: int a = 5 */
        if (node_value)
                value = atoi(node_value->data);

        /* the last $t register used in the executed cmd */
        for (i = 2; i < 10 && info.reg_t[i].var != NULL; i++)
        {
                info.reg_t[i].var = NULL, info.reg_t[i].value = 0;
                last_temp = info.reg_t[i].name;
        }

        /* li in case of no operations */
        load_type = last_temp == NULL ? "li" : "lw";

        /* store in $s register */
        for (i = 0; i < 8; i++)
        {
                if (info.reg_s[i].var == NULL
                        || strcmp(info.reg_s[i].var, info.all_lines[line_num]->tokens[1]) == 0)
                {
                        info.reg_s[i].var = info.all_lines[line_num]->tokens[1];
                        info.reg_s[i].value = last_temp ? value : atoi(info.all_lines[line_num]->tokens[3]);
                        print_inst(load_type, info.reg_s[i].name, last_temp == NULL ? info.all_lines[line_num]->tokens[3] : last_temp, NULL, NULL);
                        break;
                }
        }
        free_list(head);
        return (line_num + 1);
}
