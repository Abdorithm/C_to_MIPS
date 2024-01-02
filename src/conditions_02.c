#include "headers/main.h"

/**
 * if_condition - if condtions only
 * @line_num: line number
 * 
 * Return: the next line number after the if condition ends
*/

// if (a > 4)
// {
//	a++
// }
// else if (a > 7)
//	a++
// else 
//	a++

size_t if_condition(size_t line_num)
{
	char *a, *b, *symbol, *begining_string;
	int i = line_num, flag = 0, eql = 0;

	(void) i;
	if (info.all_lines[line_num]->size == 7)
		eql = 1;
	while (line_num < info.line_cnt)
	{
		begining_string = info.all_lines[line_num]->tokens[0];
		if (strcmp(begining_string, "if") == 0)
		{
			a = info.all_lines[line_num]->tokens[2];
			if (valid_int(a)) preprocess(a, atoi(a));
			symbol = info.all_lines[line_num]->tokens[3];
			b = info.all_lines[line_num]->tokens[4 + eql];
			if (valid_int(b)) preprocess(b, atoi(b));
			print_condition(eql, a, b, symbol, 0);
		}
		else if (strcmp(begining_string, "}") == 0)
		{
			line_num += 1;
			printf("L%d:\n", info.j_jumper);
			info.j_jumper++;
			break;
		}
		else if (strcmp(begining_string, "{") == 0 || flag == 1)
		{
			if (flag == 0)
				flag = 1;
			else
			{
				printf("\tConddddtion\n");
				/*decision(line_num);*/
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
 * @loop_or_condition : check if the 
 *	funcition were a loop or condidrtion
 * @eql : check if the condition has equal ">= , <="
 * @loop_or_condition : bool 1 or 0
*/

void print_condition(int eql, char *a, char *b, char *symbol, int loop_or_condition)
{
	char *jump = ((loop_or_condition)? strdup("Exit") : strdup("Cond"));
	int jumper = ((loop_or_condition)? info.loop_jumper : info.j_jumper);

	if(strcmp(symbol,">") == 0)
	{
		if(eql)
			printf("\tblt %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
		else
			printf("\tble %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
	}
	else if(strcmp(symbol,"<") == 0)
	{
		if(eql)
			printf("\tbgt %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
		else
			printf("\tbge %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
	}
	else if (strcmp(symbol,"!") == 0)	
		printf("\tbeq %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
	else
		printf("\tbne %s %s %s%d:\n", return_reg(a, 't').name, return_reg(b, 't').name, jump, jumper);
}

/**
 * else_or_elseif_condition - else or elseif condtions only
 * @line_num: line number
 * 
 * Return: the next line number after the else or elseif condition ends
*/

size_t else_or_elseif_condition(size_t line_num, int count_conditions)
{
	char *a, *b, *symbol, *begining_string;
	int i = line_num, flag = 0, eql = 0;

	(void) i;
	count_conditions++;
	while (line_num < info.line_cnt)
	{
		begining_string = info.all_lines[line_num]->tokens[0];
		if (strcmp(begining_string, "if") == 0)
		{
			if (info.all_lines[line_num]->size == 7)
				eql = 1;
			a = info.all_lines[line_num]->tokens[2];
			if (valid_int(a)) preprocess(a, atoi(a));
			symbol = info.all_lines[line_num]->tokens[3];
			b = info.all_lines[line_num]->tokens[4 + eql];
			if (valid_int(b)) preprocess(b, atoi(b));
			print_condition(eql, a, b, symbol, 0);
		}
		if (strcmp(begining_string, "else") == 0)
		{	
			if (info.all_lines[line_num]->size > 1)
			{
				if (info.all_lines[line_num]->size == 8)
					eql = 1;
				a = info.all_lines[line_num]->tokens[3];
				if (valid_int(a)) preprocess(a, atoi(a));
				symbol = info.all_lines[line_num]->tokens[4];
				b = info.all_lines[line_num]->tokens[5 + eql];
				if (valid_int(b)) preprocess(b, atoi(b));
				print_condition(eql, a, b, symbol, 0);
			}
		}
		else if (strcmp(begining_string, "}") == 0)
		{
			if (count_conditions > 1)
			{
				printf("\tJK%d\n", info.k_jumper);
				printf("L%d:\n", info.j_jumper);
				info.j_jumper++;
				flag = 0;
				count_conditions--;
			}
			else
			{
				printf("K%d:\n", info.k_jumper);
				info.k_jumper++;
				line_num += 1;
				return (line_num);
			}
		}
		else if (strcmp(begining_string, "{") == 0 || flag == 1)
		{
			if (flag == 0)
				flag = 1;
			else
			{
				printf("\tConddddtion\n");
				/*decision(line_num);*/
			}
		}
		line_num++;
	}
	return (line_num);
}
