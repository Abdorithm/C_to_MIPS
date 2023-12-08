#include "main.h"

/**
 * tostring - convert int to string
 * @number: the number
 *
 * Return: the string representation
*/
char *tostring(int number)
{
	int size = snprintf(NULL, 0, "%d", number);
	char *result = (char *)malloc(size + 1);

	snprintf(result, size + 1, "%d", number);

	return (result);
}

/**
 * get_argv - a function to get the command we typed using strtok.
 * @strRead: the command we typed.
 *
 * Return: array of chars.
 */
char **get_argv(char *strRead)
{
	char **argv = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = strdup(strRead);
	if (tmp == NULL)
		return (NULL);
	tmp_token = strtok(tmp, " ;");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = strtok(NULL, " ;");
	}

	free(tmp), size++;
	argv = (char **)malloc(sizeof(char *) * size);
	if (argv == NULL)
		return (NULL);
	for (i = 0; i < size - 1; i++)
	{
		token = strtok((i ? NULL : strRead), " ;");
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(argv[i]);
			free(argv);
			return (NULL);
		}
	}

	argv[size - 1] = NULL;
	return (argv);
}

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
	int i = 0, value = 0, done = 0;
	int priority[10] = {0, 1, 2, 2, 3, 4, 5, 6, 7, 7};

	while (opst[priority[i]].opcode != NULL)
	{
		tmp = head;
		while (tmp)
		{
			done = 0;
			if (strcmp(tmp->data, opst[priority[i]].opcode) == 0)
			{
				value = opst[priority[i]].f(atoi(tmp->prev->data), atoi(tmp->next->data));
				done = 1;
			}
			else if (strcmp(tmp->data, opst[priority[i + 1]].opcode) == 0)
				value = opst[priority[i + 1]].f(atoi(tmp->prev->data),
						atoi(tmp->next->data)), done = 1;
			if (done)
			{
				tmp->data = tostring(value), tmp->prev = tmp->prev->prev;
				if (tmp->prev)
				{
					free(tmp->prev->next->data), free(tmp->prev->next), tmp->prev->next = tmp;
				}
				else
					head = tmp;
				tmp->next = tmp->next->next;
				if (tmp->next)
				{
					free(tmp->next->prev->data), free(tmp->next->prev);
					tmp->next->prev = tmp;
				}
			}
			tmp = tmp->next;
		} /* print_list(head); */
		i += 2;
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
	free_list(head);

	return (value);
}

/**
 * free_2d - frees an array of strings form memory
 * @array: the array
 */
void free_2d(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i]), i++;
	free(array);
}
