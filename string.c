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
	int count = 0, extra, i;
	char *token, *str_copy = strdup(str);

	token = strtok(str_copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
		extra = 0;
		for (i = 0; token[i]; i++)
		{
			if (
				token[i] == ';' || token[i] == ',' ||
				token[i] == '(' || token[i] == ')' ||
				token[i] == '{' || token[i] == '}'
			)
			extra++;
		}
		count += extra ? extra - 1 : 0;
	}
	count++;
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
	int argCount = 0, num_tokens = 0;


	num_tokens = count_tokens(line, " \t\n");
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
	token = strtok(line, " \t\n");
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
		token = strtok(NULL, " \t\n");
	}
	arg[argCount] = NULL;
	free(line);
	return (arg);
}

