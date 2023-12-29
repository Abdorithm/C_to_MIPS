#include "headers/main.h"

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
	/*
	 if (valid_int(a))
	 {
		put int reg (atoi(a))
		print sub r,r,r
		addi r,r,a

		and the same for b
	 }
	 */
	printf("loop%d\n", info.loop_cnt);
	print_condition(eql, a, b, symbol);
	if (!strcmp("{", info.all_lines[line_num + 1]->tokens[0]))
	{
		i = line_num + 2;
		while (strcmp("}", info.all_lines[i]->tokens[0]))
		{
			printf("\tany thing until abdo fix decision\n");
			/*
			 desicion();
			 */
			i++;
		}
	}
	else
	{
		printf("\tany single line statement\n");
		/*
		 single line decision
		 */
	}
	printf("\tJ loop%d\n", info.loop_cnt);
	printf("Exit:\n");
}
