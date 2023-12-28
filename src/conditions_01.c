#include "headers/main.h"

/**
 * check_else - check if there is an else condition
 * @line_num: line number
 * 
 * Return: 0 or 1 : if 0 no else condition, if 1 there is an else condition
*/

int check_numbers_condtions(size_t line_num)
{
	int cntr = 0;
    while(line_num < info.line_cnt)
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
 * @content: content of the line
 *
 * Return: void
 */

int condition(size_t line_num)
{
	int count_condtions = 0;
	size_t new_line = 0;

 	count_condtions = check_numbers_condtions(line_num);

	if(count_condtions == 0)
		new_line = if_condition(line_num);
	else
		new_line = else_or_elseif_condition(line_num, count_condtions);

	return (new_line);
}
