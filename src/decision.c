#include "headers/main.h"

/**
 * decision - decside which operation should be preformed on the line
 * @content: content o  line
 * @counter: counter of line
 *
 * Return: void
 */
void decision(size_t counter)
{
	int num_line = 0;
	first_t frst[] = {
		{"int", calc},
		{"long", calc},
		{"if", condition},
		/*
		{"for", loop},
		{"while", loop},
		*/
		{NULL, NULL}
	};

	while (frst[num_line].first)
	{
		if (strcmp(frst[num_line].first, info.all_lines[num_line]->tokens[0]) == 0)
			frst[num_line].f(num_line);
		num_line++;
	}
}
