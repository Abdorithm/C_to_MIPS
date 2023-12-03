#include "headers/main.h"

/**
 * tostring - convert int to string
 * str[]: the string
 * num: the number
*/

void tostring(char str[], int num)
{
	int i, rem, len = 0, n;
 
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

/**
 * get_argv - a function to get the command we typed using strtok.
 * @strRead: the command we typed.
 * Return: array of chars.
 */

char **get_argv(char *strRead)
{
	char **argv = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = strdup(strRead);
	if (tmp == NULL)
		return (NULL);
	tmp_token = strtok(tmp, " ");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = strtok(NULL, " ");
	}

	free(tmp), size++;
	argv = (char **)malloc(sizeof(char *) * size);
	if (argv == NULL)
		return (NULL);
	for (i = 0; i < size - 1; i++)
	{
		token = strtok((i ? NULL : strRead), " ");
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
 * calc - calculate the value of rightside
 * @rightside: the value that have to be in register
 * Return: calculated value
 */

int calc(char *rightside)
{
	instruction_t opst[] = {
				{"+", add},
				{"-", sub},
				{"*", mul},
				{"/", divs},
				{"%", mod},
				{NULL, NULL}
				};
	char **seprateline;
	unsigned int i = 0, j= 0;
	int value = 0;

	/*{'<<', ssl},*/
	/*{'>>', ssr},*/
	seprateline = get_argv(rightside);

	i = 0;

	for (j = 0; seprateline[j] != NULL; j++)
	{
		while (opst[i].opcode != NULL)
		{			
			if (strcmp(seprateline[j], opst[i].opcode) == 0)
			{
				/*
				int c = 4 + 5 * 5  / 2;
				int c = 0 0 9 * 5  / 2;
				int c = 0 0 0 0 45 / 2;
				int c = 0 0 0 0 0  0 22;
									^
				*/
				value = opst[i].f(atoi(seprateline[j - 1]), atoi(seprateline[j + 1]));
				seprateline[j - 1] = 0;
				seprateline[j] = 0;
				tostring(seprateline[j + 1], value);
				j++;
				break;
			}
			i++;
		}
		i = 0;
	}

	return (value);
}
