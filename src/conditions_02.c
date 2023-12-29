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
	int i = line_num, flag = 0;

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
					printf("\tblt %s %s L%d\n", a, b, info.j_jumber);
				}
				else
				printf("\tble %s %s L%d\n", a, b, info.j_jumber);
			}
			else if(strcmp(symbol,"<") == 0)
			{
				if(strcmp(equal_symbol,"=") == 0)
				{
					b = info.all_lines[line_num]->tokens[5];
					printf("\tbgt %s %s L%d\n", a, b, info.j_jumber);
				}
				else
				printf("\tbge %s %s L%d\n", a, b, info.j_jumber);
			}
			else if (strcmp(symbol,"!") == 0)
			{
				b = info.all_lines[line_num]->tokens[5];
				printf("\tbeq %s %s L%d\n", a, b, info.j_jumber);
			}
			else
			printf("\tbne %s %s L%d\n", a, b, info.j_jumber);
		}
		else if (strcmp(begining_string,"}") == 0)
		{
			line_num += 1;
			printf("L%d:\n", info.j_jumber);
			info.j_jumber++;
			break;
		}
		else if (strcmp(begining_string,"{") == 0 || flag == 1)
		{
			if(flag == 0)
				flag=1;
			else
						{
								printf("   Conddddtion\n");
			}
		}
		line_num++;
	}
	return (line_num);
}

/**
 * print_condition - translate the condition into mips code
 * 
 * @a : the lhs of the condition
 * @b : the rhs of the condition
 * @symbol : the condition its self
 * @eql : check if the condition has equal ">= , <="
*/

void print_condition(int eql, char *a, char *b, char *symbol)
{
	if(strcmp(symbol,">") == 0)
	{
		if(eql)
			printf("\tblt %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
		else
		printf("\tble %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
	}
	else if(strcmp(symbol,"<") == 0)
	{
		if(eql)
			printf("\tbgt %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
		else
		printf("\tbge %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
	}
	else if (strcmp(symbol,"!") == 0)
		printf("\tbeq %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
	else
	printf("\tbne %s %s L%d\n", return_reg(a).name, b, info.j_jumber);
}

/**
 * else_or_elseif_condition - else or elseif condtions only
 * @line_num: line number
 * 
 * Return: the next line number after the else or elseif condition ends
*/
/*
size_t else_or_elseif_condition(size_t line_num, int count_condtions)
{
	char *a, *b, *symbol, *equal_symbol, *begining_string;
	int i = line_num, flag = 0;

	(void) i;
	count_condtions++;
	while(line_num < info.line_cnt)
	{
		begining_string = info.all_lines[line_num]->tokens[0]; 
		if (strcmp(begining_string, "if") == 0)
		{
			a = info.all_lines[line_num]->tokens[2];
			symbol = info.all_lines[line_num]->tokens[3];
			b = info.all_lines[line_num]->tokens[4];
			equal_symbol = info.all_lines[line_num]->tokens[4];
			print_condtion(line_num, a, b, symbol, equal_symbol);
		}
		if (strcmp(begining_string, "else") == 0)
		{
			if (info.all_lines[line_num]->size > 1)
			{
				a = info.all_lines[line_num]->tokens[3];
				symbol = info.all_lines[line_num]->tokens[4];
				b = info.all_lines[line_num]->tokens[5];
				equal_symbol = info.all_lines[line_num]->tokens[5];
				print_condtion(line_num, a, b, symbol, equal_symbol);
			}
		}
		else if (strcmp(begining_string,"}") == 0)
		{
			if(count_condtions > 1)
			{
				printf("   JK%d\n", info.k_jumber);
				printf("L%d:\n", info.j_jumber);
				info.j_jumber++;
				flag = 0;
				count_condtions--;
			}
			else
			{
				printf("K%d:\n", info.k_jumber);
				info.k_jumber++;
				line_num += 1;
				return (line_num);
			}
		}
		else if (strcmp(begining_string,"{") == 0 || flag == 1)
		{
			if(flag == 0)
				flag=1;
			else
						{
								printf("   Conddddtion\n");
			}
		}
		line_num++;
	}
	return (line_num);
}
*/
