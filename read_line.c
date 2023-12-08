#include "main.h"

/**
 * readline - read a line from file
 * @content: content of line
 * @counter: counter of line
 * @file: name file
 *
 * Return: void
 */

void readline(char *content, unsigned int counter, FILE *file)
{
	char *leftside, *rightside, *datatype, *namevar;
	char **tokens_line;

	tokens_line = get_argv(content);
	(void)file;
	(void)counter;
	(void)datatype;

	if (tokens_line == NULL)
		return;

	if (strcmp(tokens_line[0], "int") == 0 || strcmp(tokens_line[0], "double") == 0)
	{
		/*new variable in regsiter int a = 5*/
		leftside = strtok(content, "=");
		rightside = strtok(NULL, "=");

		datatype = strtok(leftside, " ");
		namevar = strtok(NULL, " ");
		put_in_register(namevar, rightside);
	}
	else if (strcmp(tokens_line[0], "if") == 0)
	{
		handel_if(tokens_line);
	}
	else if (strcmp(tokens_line[0], "while") == 0)
	{

	}
	else if (strcmp(tokens_line[0], "for") == 0)
	{

	}
	else
	{
		/*variable is already exist in register a = 5*/
	}

	/*printf("leftside: %s\n", leftside);*/
	/*printf("rightside: %s\n", rightside);*/
}
