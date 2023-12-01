#include "headers/main.h"

/**
 * put_in_register - ...
 * @namevar: ...
 * @rightside: ...
 * Return: void
*/

void put_in_register(char *namevar, char *rightside)
{
    int i = 0;

    for (i = 0; i < 8; i++)
    {
        if (regs.reg_s[i].var == NULL)
        {
            regs.reg_s[i].var = namevar;
            regs.reg_s[i].value = atoi(rightside);
            printf("namevar: %s\n", regs.reg_s[i].name);
            printf("value: %d\n", regs.reg_s[i].value);
            printf("var: %s\n", regs.reg_s[i].var);
            break;
        }
    }
}