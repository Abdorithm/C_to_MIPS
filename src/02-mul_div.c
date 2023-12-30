#include "headers/main.h"

/**
 * assign_args - assign both sides of the operation
 * if they were declared before.
 * @first_arg: left side of the operation
 * @second_arg: right side of the operation
 * @right: value of first side
 * @left: value of second side
 *
 * Return: void
 */
void assign_args(char **first_arg, char **second_arg, int right, int left)
{
    int i;

	for (i = 0; i < 10; i++)
	{
        if (info.reg_t[i].value == right)
        {
            *first_arg = info.reg_t[i].name;
            break;
        }
    }

	for (i = 0; i < 10; i++)
	{
        if (info.reg_t[i].value == left)
        {
            *second_arg = info.reg_t[i].name;
            break;
        }
    }

    if (*first_arg == NULL && *second_arg == NULL)
    {
        printf("\tsub $t0 $t0 $t0\n"
                "\taddi $t0 $t0 %d\n"
                "\tsub $t1 $t1 $t1\n"
                "\taddi $t1 $t1 %d\n", right, left);
        *first_arg = "$t0", *second_arg = "$t1";
    }
}

/**
 * mul - mul two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int mul(int right, int left)
{
    int i;
    char *first_arg = NULL, *second_arg = NULL;

    assign_args(&first_arg, &second_arg, right, left);
	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right * left;
            info.reg_t[i].var = "used";
            if (first_arg == NULL && second_arg != NULL)
                printf("\tmuli %s, %s, %i\n", info.reg_t[i].name, second_arg, right);
            else if (first_arg != NULL && second_arg == NULL)
                printf("\tmuli %s, %s, %i\n", info.reg_t[i].name, first_arg, left);
            else
                printf("\tmul %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right * left);
}

/**
 * divs - divs two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int divs(int right, int left)
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
            info.reg_t[i].value = right / left;
            info.reg_t[i].var = "used";
            if (first_arg != NULL && second_arg == NULL)
                printf("\tdivi %s, %s, %i\n", info.reg_t[i].name, first_arg, left);
            else
                printf("\tdiv %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right / left);
}
