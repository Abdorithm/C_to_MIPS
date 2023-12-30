#include "headers/main.h"

/**
 * mod - mod two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int mod(int right, int left)
{
    int i;
    char *first_arg = NULL, *second_arg = NULL;

    assign_args(&first_arg, &second_arg, right, left);
	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right % left;
            info.reg_t[i].var = "used";
            if (first_arg == NULL && second_arg != NULL)
                printf("modi %s, %s, %i\n\n", info.reg_t[i].name, second_arg, right);
            else if (first_arg != NULL && second_arg == NULL)
                printf("modi %s, %s, %i\n\n", info.reg_t[i].name, first_arg, left);
            else
                printf("mod %s, %s, %s\n\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (right % left);
}

/**
 * shift_left - shift left a number
 * @right: first number
 * @left: second number
 * Return: result
 */
int shift_left(int right, int left)
{
    int i;

	printf("sub $t0, $t0, $t0\n"
			"addi $t0, $t0, %d\n", right);

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right << left;
            info.reg_t[i].var = "used";
            printf("sll %s, $t0, %d\n\n", info.reg_t[i].name, left);
            break;
        }
    }
	return (right << left);
}

/**
 * shift_right - shift right a number
 * @right: first number
 * @left: second number
 * Return: result
 */
int shift_right(int right, int left)
{
    int i;

	printf("sub $t0, $t0, $t0\n"
			"addi $t0, $t0, %d\n", right);

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = right >> left;
            info.reg_t[i].var = "used";
            printf("slr %s, $t0, %d\n\n", info.reg_t[i].name, left);
            break;
        }
    }
	return (right >> left);
}
