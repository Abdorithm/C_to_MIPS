#include "headers/main.h"

/**
 *read_line - ...
 *@content: ...
 *@counter: ...
 *@file: ...
 *Return: string or null
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
		/*new variable in regsiter*/
		put_in_register(namevar, rightside);
	}
	else
	{
		/*variable is already exist in register*/
	}

	printf("leftside: %s\n", leftside);
	printf("rightside: %s\n", rightside);
}
