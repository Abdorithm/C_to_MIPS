#include "headers/main.h"

/**
 * decision - decside which operation should be preformed on the line
 *
 * @line: line number
 *
 * Return: void
 */
size_t decision(size_t line)
{
        size_t which = 0, i = 0;

        first_t first[] = {
                {"int", calc},
                {"long", calc},
                {"if", condition},
                {"for", for_loop},
                {"while", while_loop},
                {NULL, NULL}
        };

        while (first[i].first)
        {
                if (strcmp(first[i].first, info.all_lines[line]->tokens[0]) == 0)
                {
                        which = first[i].f(line);
                }
                i++;
        }
        return (which);
}
