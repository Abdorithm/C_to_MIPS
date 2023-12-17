#include "headers/main.h"

/**
 * if_condition - if condtions only
 * @line_num: line number
 * 
 * Return: the next line number after the if condition ends
*/

int if_condition(size_t line_num)
{
	char *a= info.all_lines[line_num]->tokens[2];
	char *b= info.all_lines[line_num]->tokens[4];
	char *symbol= info.all_lines[line_num]->tokens[3];
	char *equal_symbol= info.all_lines[line_num]->tokens[4];
	int i = line_num, flag =0;

	(void) i;
	while(line_num < info.line_cnt)
	{
		char*begining_string = info.all_lines[line_num]->tokens[0]; 
		if (strcmp(begining_string, "if") == 0)
		{
			if(strcmp(symbol,">") == 0)
			{
				if(strcmp(equal_symbol,"=") == 0)
				{
					b = info.all_lines[line_num]->tokens[5];
					printf("   blt %s %s L%d\n", a, b, info.number_jump);
				}
				else
					printf("   ble %s %s L%d\n", a, b, info.number_jump);
			}
			else if(strcmp(symbol,"<") == 0)
			{
				if(strcmp(equal_symbol,"=") == 0)
				{
					b = info.all_lines[line_num]->tokens[5];
					printf("   bgt %s %s L%d\n", a, b, info.number_jump);
				}
				else
					printf("   bge %s %s L%d\n", a, b, info.number_jump);
			}
			else if (strcmp(symbol,"!") == 0)
			{
				b = info.all_lines[line_num]->tokens[5];
				printf("   beq %s %s L%d\n", a, b, info.number_jump);
			}
			else
				printf("   bne %s %s L%d\n", a, b, info.number_jump);
		}
		else if (strcmp(begining_string,"}") == 0)
		{
			line_num++;
			printf("L%d:\n", info.number_jump);
			info.number_jump++;
			break;
		}
		else if (strcmp(begining_string,"{") == 0 || flag == 1)
		{
			if(flag == 0)
				flag=1;
			else
			{
				printf("   Conddddtion\n");
				/*decision(line_num);*/
			}
		}
		line_num++;
	}
	return (line_num);
}

/**
 * condition - if condtions and else condtions
 * @content: content of the line
 *
 * Return: void
 */

int condition(size_t line_num)
{
	/*count_elseif = counts_elseif();
	count_else = counts_else();*/
	size_t new_line;

	new_line = if_condition(line_num);
	/*if(count_elseif == 0)
	{
		if(count_else == 0)
		{

		   print_if_cond(line_num); 
		}
		else
		{
			prinf_else(line_num);
		}
	}
	else
	{
	   while(count_elseif)
	   {
		 print_else_if();
		 count_elseif --;
	   }
	}*/
	return (new_line);
}
