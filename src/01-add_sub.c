#include "headers/main.h"

/**
 * add - add two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int add(int right, int left)
{
    int i;
    char *first_arg = NULL, *second_arg = NULL;

    assign_args(&first_arg, &second_arg, right, left);
	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right + left;
            info.reg_t[i].var = "used";
            if (first_arg == NULL && second_arg != NULL)
                printf("addi %s, %s, %i\n\n", info.reg_t[i].name, second_arg, right);
            else if (first_arg != NULL && second_arg == NULL)
                printf("addi %s, %s, %i\n\n", info.reg_t[i].name, first_arg, left);
            else
                printf("add %s, %s, %s\n\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right + left);
}

/**
 * sub - sub two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int sub(int right, int left)
{
    int i;
    char *first_arg = NULL, *second_arg = NULL;

    assign_args(&first_arg, &second_arg, right, left);

    if (first_arg == NULL && second_arg != NULL)
    {
        printf("sub $t0 $t0 $t0\n"
                "addi $t0 $t0 %d\n", right);
        first_arg = "$t0";
    }

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right - left;
            info.reg_t[i].var = "used";
            if (first_arg != NULL && second_arg == NULL)
                printf("subi %s, %s, %i\n\n", info.reg_t[i].name, first_arg, left);
            else
                printf("sub %s, %s, %s\n\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right - left);
}
