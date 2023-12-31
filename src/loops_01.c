#include "headers/main.h"

/**
 * count_loop_tokens - count the tokens to initialize the loop
 *
 * @line_num : the number of the line
 * @init : the counter for loop initial statement
 * @cond : the counter for loop condition statement
 * @increament : the counter for loop increament statement
 * Return: the number of tokens
*/

void count_loop_tokens(size_t line_num, int *init, int *cond, int *increament)
{
	size_t open_bracket = 1, close_bracket = info.all_lines[line_num]->size - 1;
	size_t first_semicolon = 0, last_semicolon = 0, i = 0;

	for (; i < info.all_lines[line_num]->size; i++)
	{
		if (!strcmp(";", info.all_lines[line_num]->tokens[i]))
		{
			if (!first_semicolon)
				first_semicolon = i;
			else
				last_semicolon = i;
		}
	}
	*init = first_semicolon - open_bracket - 1;
	*cond = last_semicolon - first_semicolon - 1;
	*increament = close_bracket - last_semicolon - 1;
}


/**
 * num_operation - put a num in the register
 *
 * @name : the name of the variable
 * @num : the value of the va riable
*/

void preprocess(char *name, int num)
{
	put_in_register(name, num, 't');
        print_inst("sub", return_reg(name).name, return_reg(name).name, return_reg(name).name, NULL);
        print_inst("addi", return_reg(name).name, return_reg(name).name, tostring(return_reg(name).value), NULL);

}

/**
 * while_loop - translate the while loop statement to mips code
 *
 * @line_num : the number of the line
*/

size_t while_loop(size_t line_num)
{
	char *a, *b, *symbol;
	int eql = 0, i = line_num + 2;

	if (info.all_lines[line_num]->size == 6)
		b = info.all_lines[line_num]->tokens[4];
	else
	{
		eql = 1;
		b = info.all_lines[line_num]->tokens[5];
	}
	a = info.all_lines[line_num]->tokens[2];
	symbol = info.all_lines[line_num]->tokens[3];
	if (valid_int(a))
		preprocess(a, atoi(a));
	if (valid_int(b))
		preprocess(b, atoi(b));
        print_inst("loop", NULL, NULL, tostring(info.loop_jumper), NULL);
	print_condition(eql, a, b, symbol, 1);
	if (!strcmp("{", info.all_lines[line_num + 1]->tokens[0]))
	{
		while (strcmp("}", info.all_lines[i]->tokens[0]))
		{
			decision(i);
			i++;
		}
		i++;
	}
	else
		decision(i - 1);
        print_inst("J", NULL, NULL, "loop", tostring(info.loop_jumper));
        print_inst("Exit", NULL, NULL, tostring(info.loop_jumper), NULL);
	info.loop_jumper++;
	return(i);
}

/**
 * for_loop - translate the for loops statement to mips code
 *
 * @line_num : the number of the line
*/

size_t for_loop(size_t line_num)
{
	int cnt_init, cnt_cond, cnt_increament, eql, i = line_num + 2;
	char *a, *b, *symbol;

	count_loop_tokens(line_num, &cnt_init, &cnt_cond, &cnt_increament);
	a = info.all_lines[line_num]->tokens[cnt_init - 1];
	b = info.all_lines[line_num]->tokens[cnt_init + 1];
	preprocess(a , atoi(b));
	a = info.all_lines[line_num]->tokens[cnt_init + 3];
	if (valid_int(a))  preprocess(a, atoi(a));
	symbol = info.all_lines[line_num]->tokens[cnt_init + 4];
	eql = ((cnt_cond == 4)? 1 : 0);
	b = info.all_lines[line_num]->tokens[cnt_init + 5 + eql];
	if (valid_int(b)) preprocess(b, atoi(b));
        print_inst("loop", NULL, NULL, tostring(info.loop_jumper), NULL);
	print_condition(eql, a, b, symbol, 1);
	if (!strcmp("{", info.all_lines[line_num + 1]->tokens[0]))
	{
		while (strcmp("}", info.all_lines[i]->tokens[0]))
		{
			decision(i);
			i++;
		}
		i++;
                print_inst("addi", return_reg(a).name, return_reg(a).name, tostring(1), NULL);
		/* handle increament */
	}
	else
	{
		decision(i - 1);
                print_inst("addi", return_reg(a).name, return_reg(a).name, tostring(1), NULL);
	}
        print_inst("J", NULL, NULL, "loop", tostring(info.loop_jumper));
        print_inst("Exit", NULL, NULL, tostring(info.loop_jumper), NULL);
	info.loop_jumper++;
	return (i);
}
