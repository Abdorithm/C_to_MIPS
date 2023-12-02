#include "headers/main.h"

/**
 *read_line - read a line from file
 *@content: content of line
 *@counter: counter of line
 *@file: name file
 *Return: void
 */

void readline(char *content, unsigned int counter, FILE *file)
{
	char *leftside, *rightside, *datatype, *namevar;

	(void)file;
	(void)counter;
	leftside = strtok(content, "=");
	rightside = strtok(NULL, "=");

	datatype = strtok(leftside, " ");
	namevar = strtok(NULL, " ");
	(void)datatype;

	if (namevar != NULL)
	{
		/*new variable in regsiter int a = 5*/
		put_in_register(namevar, rightside);
	}
	else
	{
		/*variable is already exist in register a = 5*/
	}

	/*printf("leftside: %s\n", leftside);*/
	/*printf("rightside: %s\n", rightside);*/
}
