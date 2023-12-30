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
        printf("sub $t0 $t0 $t0\n"
                "addi $t0 $t0 %d\n"
                "sub $t1 $t1 $t1\n"
                "addi $t1 $t1 %d\n", right, left);
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
                printf("muli %s, %s, %i\n\n", info.reg_t[i].name, second_arg, right);
            else if (first_arg != NULL && second_arg == NULL)
                printf("muli %s, %s, %i\n\n", info.reg_t[i].name, first_arg, left);
            else
                printf("mul %s, %s, %s\n\n", info.reg_t[i].name, first_arg, second_arg);
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
        printf("sub $t0 $t0 $t0\n"
                "addi $t0 $t0 %d\n", right);
        first_arg = "$t0";
    }

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right / left;
            info.reg_t[i].var = "used";
            if (first_arg != NULL && second_arg == NULL)
                printf("divi %s, %s, %i\n\n", info.reg_t[i].name, first_arg, left);
            else
                printf("div %s, %s, %s\n\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right / left);
}
