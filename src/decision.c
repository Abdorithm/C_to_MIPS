#include "headers/main.h"

/**
 * decision - decside which operation should be preformed on the line
 * @content: content o  line
 * @counter: counter of line
 *
 * Return: void
 */
void decision(notUsed char *content, notUsed unsigned int counter)
{
	int num_line = 0;
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

	while (first[num_line].first)
	{
		if (strcmp(first[num_line].first, info.all_lines[num_line]->tokens[0]) == 0)
			first[num_line + 1].f(num_line);
		num_line++;
	}

}
