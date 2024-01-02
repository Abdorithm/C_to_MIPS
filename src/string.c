#include "headers/main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tostring - convert int to string
 * @number: the number
 *
 * Return: the string representation
*/
char *tostring(int number)
{
	int size = snprintf(NULL, 0, "%d", number);
	char *result = (char *)malloc(size + 1);

	snprintf(result, size + 1, "%d", number);

	return (result);
}
/**
 * count_tokens - count the number of tokens in a string
 *
 * @str: the string to count tokens in
 * @delim: the delimiter used to split the string into tokens
 *
 * Return: the number of tokens in the string
 */
int count_tokens(const char *str, const char *delim)
{
	size_t count = 0, expres, i;
	char *token, *str_copy;


	str_copy = strdup(str);
	token = strtok(str_copy, delim);
	while (token)
	{
		expres = 0;
		for (i = 0; token[i]; i++)
		{
			if (expr_check(token[i]))
			{
				if (i && !expr_check(token[i - 1]))
					expres++;
				expres++;
			}
		}
		/*
		 * this line for an edge case like this
		 * var = x
		 * without it the number of tokens will be 2
		 * but as you see it has to be 3
		 */
		if (!expr_check(token[strlen(token) - 1]))
			expres++;

		/* count the expressions to make room for it later */
		count += expres;

		token = strtok(NULL, delim);
	}
	free(str_copy);
	return (count);
}

/**
 * get_argv - split the line to multiple tokens
 *
 * Return: the number of tokens allocated
 */
size_t get_argv(void)
{
	char *token;
	size_t tokens_cnt;
	int cnt = 0;


	tokens_cnt = count_tokens(info.curr_line, " \t\n");

	if (!tokens_cnt)
		return (0);

	info.curr_tokens = malloc(sizeof(char *) * (tokens_cnt + 1));
	if (info.curr_tokens == NULL)
		malloc_failed();

	token = strtok(info.curr_line, " \t\n");
	while (token)
	{
		while (*token)
			info.curr_tokens[cnt++] = slice_token(&token);

		token = strtok(NULL, " \t\n");
	}
	info.curr_tokens[tokens_cnt] = NULL;
	free(info.curr_line);
	info.curr_line = NULL;
	return (tokens_cnt);
}

/**
 * slice_token - slice a given token by the expression in it
 *
 * @token: the addrss of the token to be sliced
 *
 * Return: a pointer to the new slice of token
 */
char *slice_token(char **token)
{
	size_t slice_size = 0;
	char *new_slice = NULL;

	slice_size = strcspn(*token, ";,(){}&|<>*/%+-=");

	/* one of the delimiters */

	if (slice_size == 0)
		slice_size++;

	new_slice = malloc(sizeof(char) * (slice_size + 1));

	/* need to free before exist to be implemented */
	if (!new_slice)
		malloc_failed();

	strncpy(new_slice, *token, slice_size);
	new_slice[slice_size] = '\0';
	*token += slice_size;
	return (new_slice);
}

/**
 * print_inst - print an instruction with colors
 *
 * @inst: the instruction
 * @reg1: the register
 * @reg2: the register
 * @imd: extra
 */
void print_inst(char *inst, char *reg1, char *reg2, char *imd, char *num)
{
        if (reg1 == NULL && num == NULL) /* label */
        {
                printf("$"ORANGE);
                printf("%s%s", inst, imd);
                printf(RESET);
                printf(":\n");
                printf(RESET);
                return;
        }
        printf(LIGHTGREEN);
        printf("\t%s\t", inst);
        printf(RESET"$"CYAN);
        if (inst[0] == 'J')
        {
                printf(ORANGE);
                printf("%s%s\n", imd, num);
                printf(RESET);
                return;
        }
        printf("%s", reg1);
        if (isdigit(*reg2))
        {
                printf(RESET", ");
                printf("%s", reg2); 
        }
        else 
        {

                printf(RESET", $"CYAN);
                printf("%s", reg2);
                printf(RESET);
        }
        if (imd == NULL)
        {
                printf("\n");
                return;
        }

        printf(", ");
        if (num)
        {
                printf("$"ORANGE);
                printf("%s%s\n", imd, num);
                printf(RESET);
                return;
        }
        if (!isdigit(*imd))
                printf("$"CYAN);
        printf("%s\n", imd);
        printf(RESET);
        
}

