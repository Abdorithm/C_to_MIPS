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

	first_word = strtok(content, " ");
	rest_of_line = strtok(NULL, " ");
	while (frst[i].first)
	{
		if (strcmp(frst[i].first, first_word))
			frst[i].f(rest_of_line);
		i++;
	}
}
