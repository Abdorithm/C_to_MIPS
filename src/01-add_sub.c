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
                printf("\taddi %s, %s, %i\n", info.reg_t[i].name, second_arg, right);
            else if (first_arg != NULL && second_arg == NULL)
                printf("\taddi %s, %s, %i\n", info.reg_t[i].name, first_arg, left);
            else
                printf("\tadd %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
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
        printf("\tsub $t0 $t0 $t0\n"
                "\taddi $t0 $t0 %d\n", right);
        first_arg = "$t0";
    }

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right - left;
            info.reg_t[i].var = "used";
            if (first_arg != NULL && second_arg == NULL)
                printf("\tsubi %s, %s, %i\n", info.reg_t[i].name, first_arg, left);
            else
                printf("\tsub %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right - left);
}
