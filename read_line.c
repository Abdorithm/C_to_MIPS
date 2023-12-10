#include "headers/main.h"

/**
 * readline - read a line from file
 * @content: content of line
 * @counter: counter of line
 *
 * Return: void
 */
void readline(char *content, notUsed unsigned int counter)
{
	char **tokens = get_argv(content);
	int i;

	for (i = 0; tokens[i]; i++)
	{
		printf("%s\n", tokens[i]);
	}
}
