#include "headers/main.h"
#include <stdlib.h>
#include <string.h>

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

        if (info.all_lines[line]->size > 1 &&
                !strcmp("=", info.all_lines[line]->tokens[1]))
        {
                fake_int(line);
        }
        while (first[i].first)
        {
                if (strcmp(first[i].first, info.all_lines[line]->tokens[0]) == 0)
                        which = first[i].f(line);
                i++;
        }
        return (which);
}

/*
*
* fake_int - add a fake 'int' to the start of the tokens
*
*/
void fake_int(size_t line)
{
        char **tokens = info.all_lines[line]->tokens;
        char **new_tokens = NULL;
        size_t i, size = info.all_lines[line]->size;

        new_tokens = malloc(sizeof(char *) * (size + 2));
        if (new_tokens == NULL)
                malloc_failed();

        new_tokens[0] = strdup("int");
        for (i = 0; i <= size; i++)
                new_tokens[i + 1] = tokens[i];

        free(tokens);
        info.all_lines[line]->tokens = new_tokens;
        info.all_lines[line]->size++;
}
