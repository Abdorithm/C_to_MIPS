#include "headers/main.h"

/**
 * decision - decside which operation should be preformed on the line
 * @content: content o  line
 * @counter: counter of line
 *
 * Return: void
 */
void decision(char *content, notUsed unsigned int counter)
{
	char *first_word, *rest_of_line;
	int i = 0;
	first_t frst[] = {
		{"int", calc},
		{"long", calc},
		/*
		{"if", condition},
		{"else", condition},
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
