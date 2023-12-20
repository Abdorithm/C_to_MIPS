#include "headers/main.h"

/**
 * expr_check - check if a char is an expression
 * @ch: the char to check
 *
 * Return: 1 if it is otherwise 0
*/
int expr_check(char ch)
{
	char expressions[] = {
		';', ',', '(', ')',
		'{', '}', '&', '|',
		'>', '<', '*', '/',
		'%', '+', '-', '='

	};
	int size = sizeof(expressions) / sizeof(char);
	int i;

	for (i = 0; i < size; i++)
	{
		if (ch == expressions[i])
			return (1);
	}
	return (0);
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
		return (info.reg_s);

	if ('a' == reg_name)
		return (info.reg_a);

	if ('t' == reg_name)
		return (info.reg_t);

	if ('v' == reg_name)
		return (info.reg_v);

	return (NULL);
}

/**
 * put_in_register - put a new variable in register
 * @name_var: name of variable
 * @value: the value to store
 * @reg_name: name of the register
 *
 * Return: void
*/
void put_in_register(char *name_var, int value, char reg_name)
{
	int i;
	reg *curr_reg = info.get_reg(reg_name);

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

