#include "headers/main.h"

void num_operation(char *num)
{
	put_in_register(num, atoi(num), 't');
	printf("sub %s %s %s\n", return_reg(num, 't').name, return_reg(num, 't').name, return_reg(num, 't').name);
	printf("addi %s %s %d\n", return_reg(num, 't').name, return_reg(num, 't').name, return_reg(num, 't').value);
}

/**
 * whlie_loop - translate the while loop statement to mips code
 *
 * @line_num : the number of the line
*/

void while_loop(size_t line_num)
{
	char *a, *b, *symbol;
	int eql, i;

	if (info.all_lines[line_num]->size == 6)
	{
		eql = 0;
		b = info.all_lines[line_num]->tokens[4];
	}
	else
	{
		eql = 1;
		b = info.all_lines[line_num]->tokens[5];
	}
	a = info.all_lines[line_num]->tokens[2];
	symbol = info.all_lines[line_num]->tokens[3];
	if (valid_int(a))
		num_operation(a);
	if (valid_int(b))
		num_operation(b);
	printf("loop%d:\n", info.loop_cnt);
	print_condition(eql, a, b, symbol);
	if (!strcmp("{", info.all_lines[line_num + 1]->tokens[0]))
	{
		i = line_num + 2;
		while (strcmp("}", info.all_lines[i]->tokens[0]))
		{
			i++;
		}
	}
	else
	{
		printf("\tsingle line loop\n");
		/*
		 single line decision
		 */
	}
	printf("\tJ loop%d\n", info.loop_cnt);
	printf("Exit:\n");
	info.loop_cnt++;
}

/**
 * for_loop - translate the for loops statement to mips code
 *
 * @line_num : the number of the line
*/


