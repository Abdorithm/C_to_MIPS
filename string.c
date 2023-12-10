#include "headers/main.h"
#include <stdlib.h>
#include <string.h>

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
	int count = 0, expres, i;
	char *token, *str_copy;


	str_copy = strdup(str);
	token = strtok(str_copy, delim);
	while (token)
	{
		expres = 0;
		for (i = 0; token[i]; i++)
		{
			if (expr_check(token[i]))
			{
				if (i && !expr_check(token[i - 1]))
					expres++;
				expres++;
			}
		}
		/* this line for an edge case like this
		 * var = x
		 * without it the number of tokens will be 2
		 * but as you see it has to be 3
		 */
		if (!expr_check(token[strlen(token) - 1]))
			expres++;

		/* count the expressions to make room for it later */
		count += expres;
	
		token = strtok(NULL, delim);
	}
	free(str_copy);
	return (count);
}

/**
 * get_argv - split the line to multple strings
 *
 * @line: the line to tokenize
 *
 * Return: a pointer to the strings on success and NULL on failure
 */
char **get_argv(char *line)
{
	char *token;
	char **arg = NULL;
	int tokens_cnt;
	int cnt = 0;


	tokens_cnt = count_tokens(line, " \t\n");

	if (!tokens_cnt)
	{
		free(line);
		return (NULL);
	}

	arg = malloc(sizeof(char *) * (tokens_cnt + 1));
	if (arg == NULL)
	{
		perror("error: allocating arg\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token)
	{
		while (*token)
			arg[cnt++] = slice_token(&token);

		token = strtok(NULL, " \t\n");
	}
	arg[tokens_cnt] = NULL;
	free(line);
	return (arg);
}

/**
 * slice_token - slice a given token by the expression in it
 *
 * 
 */
char *slice_token(char **token)
{
	size_t slice_size;
	char *new_slice;

	slice_size = strcspn(*token, ";,(){}&|<<*/%+-=");

	/* one of the delimiters */

	if (slice_size == 0)
		slice_size++;
		
	new_slice = malloc(sizeof(char) * (slice_size + 1));

	/* need to free before exist to be implemented */
	if (!new_slice)
		malloc_failed();

	strncpy(new_slice, *token, slice_size);
	*token += slice_size;
	return (new_slice);
}
