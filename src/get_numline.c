#include "headers/main.h"

/**
 * line_numb - get the line number of the if condition
 * 
 * Return: the line number of the if condition
 */

size_t line_numb(void)
{
	size_t i = 0;

	for (i = 0; i < info.line_cnt; i++)
	{
		if(strcmp(info.all_lines[i]->tokens[0],"if") == 0)
			return (i);
	}
}
