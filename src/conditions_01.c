#include "headers/main.h"

/**
 * check_numbers_condtions - check the number of if conditions
 * @line_num: line number
 *
 * Return: the number of if conditions
*/

int check_numbers_condtions(size_t line_num)
{
	int cntr = 0;

	while (line_num < info.line_cnt)
	{
		if (strcmp(info.all_lines[line_num]->tokens[0], "}") == 0)
		{
			line_num++;
			if (line_num >= info.line_cnt)
				return (cntr);
			if (strcmp(info.all_lines[line_num]->tokens[0], "else") == 0)
				cntr++;
			else
				return (cntr);
		}
		line_num++;
	}
	return (cntr);
}

/**
 * condition - if condtions and else condtions
 * @line_num: the line number
 *
 * Return: void
 */

size_t condition(size_t line_num)
{
	int count_condtions = 0;
	size_t new_line = 0;

	count_condtions = check_numbers_condtions(line_num);

	if (count_condtions == 0)
		new_line = if_condition(line_num);
	else
		new_line = else_or_elseif_condition(line_num, count_condtions);

	return (new_line);
}
