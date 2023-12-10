#include "headers/main.h"

/**
 * check - check if it's a mathematical operation
 * @rightside: the rightside of the line
 *
 * Return: 1 if it is otherwise 0
*/
int check(char *rightside)
{
	int i = 0;

	for (i = 0; rightside[i] != '\0'; i++)
	{
		if (rightside[i] == '+' || rightside[i] == '-'
			|| rightside[i] == '*' || rightside[i] == '/'
			|| rightside[i] == '<' || rightside[i] == '>')
			return (0);
	}
	return (1);
}
/**
 * get_reg - return an array for the corresponding register name
 *
 * @reg_name: register name
 *
 * Return: register array if found otherwise NULL
 */
reg *get_reg(char reg_name)
{
	if ('s' == reg_name)
		return (regs.reg_s);

	if ('a' == reg_name)
		return (regs.reg_a);

	if ('t' == reg_name)
		return (regs.reg_t);

	if ('v' == reg_name)
		return (regs.reg_v);

	return (NULL);
}

/**
 * put_in_register - put a new variable in register
 * @namevar: name of register
 * @rightside: the value that have to be in register
 *
 * Return: void
*/
void put_in_register(char *name_var, int value, char reg_name)
{
	int i;
	reg *curr_reg = regs.get_reg(reg_name);

	if (!curr_reg)
		return;

	for (i = 0; curr_reg[i].name; i++)
	{
		if (curr_reg[i].var == NULL)
		{
			curr_reg[i].var = name_var;
			curr_reg[i].value = value;
			return;
		}
	}
}
