#include "headers/main.h"

/**
 * put_in_register - put a new variable in register
 * @namevar: name of register
 * @rightside: the value that have to be in register
 * Return: void
*/

void put_in_register(char *namevar, char *rightside)
{
    int i = 0, value;

    value = atoi(rightside);
    /*if value == 0 that is mean the rightside is not a number*/
    if (value == 0)
        value = calc(rightside);
    for (i = 0; i < 8; i++)
    {
        if (regs.reg_s[i].var == NULL)
        {
            regs.reg_s[i].var = namevar;
            regs.reg_s[i].value = value;
            printf("namevar: %s\n", regs.reg_s[i].name);
            printf("value: %d\n", regs.reg_s[i].value);
            printf("var: %s\n", regs.reg_s[i].var);
            break;
        }
    }
}