#include "headers/main.h"

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
 * count_tokens - count the number of tokens in a string
 *
 * @str: the string to count tokens in
 * @delim: the delimiter used to split the string into tokens
 *
 * Return: the number of tokens in the string
 */
int count_tokens(const char *str, const char *delim)
{
	int count = 0;
	char *token, *str_copy = strdup(str);

	token = strtok(str_copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;
	free(str_copy);
	return (count);
}

/**
 * tokenize - split the line to multple strings
 *
 * @line: the line to tokenize
 *
 * Return: a pointer to the strings on success and NULL on failure
 */
char **get_argv(char *line)
{
	char *token;
	char **arg = NULL;
	int argCount = 0, num_tokens = 0;


	num_tokens = count_tokens(line, "; \t\n");
	if (num_tokens == 1)
	{
		free(line);
		return (NULL);
	}
	arg = malloc(sizeof(char *) * num_tokens);
	if (arg == NULL)
	{
		perror("error: allocating arg\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "; \t\n");
	while (token)
	{
		arg[argCount] = strdup(token);
		if (arg[argCount++] == NULL)
		{
			perror("error: allocating arg\n");
			free(line);
			free_2d(arg);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, "; \t\n");
	}
	arg[argCount] = NULL;
	free(line);
	return (arg);
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
	char *lhs = strtok(rightside, " =");
	char *rhs = strtok(NULL, " ;");
	char **separateline = get_argv(rhs);
	int value = 0;
	expr_t *head = fill_linked_list(separateline);

	free_2d(separateline); /* we don't need it anymore! */
	value = do_priority(opst, head);
	print_list(head);
	free_list(head);
	put_in_register(lhs, value, 's');
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
		free(array[i++]);
	free(array);
}
