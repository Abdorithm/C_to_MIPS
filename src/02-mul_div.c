#include "headers/main.h"

/**
 * prev_temps - assign both parts of the operation
 * if a local variable is included.
 * @first_arg: right side
 * @second_arg: left side
 * @right_s: ...
 * @left_s: ...
 * @left: ...
 * @right: ...
 *
 * Return: void 
 */
void prev_temps(char notUsed **first_arg, char **second_arg, char *left_s, char *right_s, int *left, int *right)
{
    int i;

	for (i = 0; i < 8; i++)
	{
        if (info.reg_s[i].var != NULL && strcmp(info.reg_s[i].var, left_s) == 0)
        {
            *first_arg = info.reg_s[i].name;
            *left = info.reg_s[i].value;
            break;
        }
    }

	for (i = 0; i < 8; i++)
	{
        if (info.reg_s[i].var != NULL && strcmp(info.reg_s[i].var, right_s) == 0)
        {
            *second_arg = info.reg_s[i].name;
            *right = info.reg_s[i].value;
            break;
        }
    }
}

/**
 * assign_args - assign both sides of the operation
 * if they were declared before.
 * @first_arg: right side of the operation
 * @second_arg: left side of the operation
 * @left: value of first side
 * @right: value of second side
 *
 * Return: void
 */
void assign_args(char **first_arg, char **second_arg, int left, int right)
{
    int i;

	for (i = 0; i < 10 && *first_arg == NULL; i++)
	{
        if (info.reg_t[i].value == left)
        {
            *first_arg = info.reg_t[i].name;
            break;
        }
    }

	for (i = 0; i < 10 && *second_arg == NULL; i++)
	{
        if (info.reg_t[i].value == right)
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
                "\taddi $t1 $t1 %d\n", left, right);
        *first_arg = "$t0", *second_arg = "$t1";
    }
}

/**
 * mul - mul two numbers
 * @left_s: first number
 * @right_s: second number
 * @line_num: ...
 * Return: result
 */
int mul(char *left_s, char *right_s, size_t line_num)
{
    int i, left = INT_MAX, right = INT_MAX;
    char *first_arg = NULL, *second_arg = NULL;

    prev_temps(&first_arg, &second_arg, left_s, right_s, &left, &right);

    if (left == INT_MAX)
        left = atoi(left_s);
    if (right == INT_MAX)
        right = atoi(right_s);

    assign_args(&first_arg, &second_arg, left, right);
	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = left * right;
            info.reg_t[i].var = info.all_lines[line_num]->tokens[1];
            if (first_arg == NULL && second_arg != NULL)
                printf("\tmuli %s, %s, %i\n", info.reg_t[i].name, second_arg, left);
            else if (first_arg != NULL && second_arg == NULL)
                printf("\tmuli %s, %s, %i\n", info.reg_t[i].name, first_arg, right);
            else
                printf("\tmul %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (left * right);
}

/**
 * divs - divs two numbers
 * @left_s: first number
 * @right_s: second number
 * @line_num: ...
 * Return: result
 */
int divs(char *left_s, char *right_s, size_t line_num)
{
    int i, left = INT_MAX, right = INT_MAX;
    char *first_arg = NULL, *second_arg = NULL;

    prev_temps(&first_arg, &second_arg, left_s, right_s, &left, &right);

    if (left == INT_MAX)
        left = atoi(left_s);
    if (right == INT_MAX)
        right = atoi(right_s);

    assign_args(&first_arg, &second_arg, left, right);

    if (first_arg == NULL && second_arg != NULL)
    {
        printf("\tsub $t0 $t0 $t0\n"
                "\taddi $t0 $t0 %d\n", left);
        first_arg = "$t0";
    }

	for (i = 2; i < 10; i++)
	{
		if (info.reg_t[i].var == NULL)
        {
            info.reg_t[i].value = left / right;
            info.reg_t[i].var = info.all_lines[line_num]->tokens[1];
            if (first_arg != NULL && second_arg == NULL)
                printf("\tdivi %s, %s, %i\n", info.reg_t[i].name, first_arg, right);
            else
                printf("\tdiv %s, %s, %s\n", info.reg_t[i].name, first_arg, second_arg);
            break;
        }
	}
	return (left / right);
}
