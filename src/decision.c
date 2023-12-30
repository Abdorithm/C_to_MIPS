#include "headers/main.h"

/**
 * decision - decside which operation should be preformed on the line
 *
 * @line: line number
 *
 * Return: void
 */
void decision(size_t line)
{
	size_t which = 0;

	first_t first[] = {
		{"int", calc},
		{"long", calc},
		{"if", condition},
		/**
		 *
		 * {"for", loop},
		 * {"while", loop},
		 */
		{NULL, NULL}
	};

	while (first[which].first)
	{
		if (strcmp(first[which].first, info.all_lines[line]->tokens[0]) == 0)
			first[which].f(line);
		which++;
	}
}
