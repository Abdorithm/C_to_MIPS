#include "main.h"

/**
 *read_line - ...
 *Return: string or null
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
