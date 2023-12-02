#include "headers/main.h"

/**
 * check - check if the rightside is a number or not
 * @rightside: the rightside of the line
 * Return: 1 if it is a number and 0 if not
*/

int check(char *rightside)
{
	int i = 0;

	for (i = 0; rightside[i] != '\0'; i++)
	{
		if (rightside[i] == '+' || rightside[i] == '-' || rightside[i] == '*' || rightside[i] == '/')
			return (0);
	}
	return (1);
}

/**
 * put_in_register - put a new variable in register
 * @namevar: name of register
 * @rightside: the value that have to be in register
 * Return: void
*/

void put_in_register(char *namevar, char *rightside)
{
	int i = 0, value;

	/*if value == 0 that is mean the rightside is not a number*/
	check(rightside);
	if (check(rightside) == 0)
		value = calc(rightside);
	else
		value = atoi(rightside);

	/*printf("valueeee: %d\n", value);*/

	for (i = 0; i < 8; i++)
	{
		if (regs.reg_s[i].var == NULL)
		{
			regs.reg_s[i].var = namevar;
			regs.reg_s[i].value = value;
			printf("lw %s $t2\n", regs.reg_s[i].name);
			/*printf("namevar: %s\n", regs.reg_s[i].name);*/
			/*printf("value: %d\n", regs.reg_s[i].value);*/
			/*printf("var: %s\n", regs.reg_s[i].var);*/
			break;
		}
	}
}
