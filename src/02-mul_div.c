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

                print_inst("sub", "t0", "t0", "t0", NULL);
                print_inst("addi", "t0", "t0", tostring(left), NULL);
                print_inst("sub", "t1", "t1", "t1", NULL);
                print_inst("addi", "t0", "t0", tostring(right), NULL);

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
                                print_inst("muli", info.reg_t[i].name, second_arg, tostring(left), NULL);
                        else if (first_arg != NULL && second_arg == NULL)
                                print_inst("muli", info.reg_t[i].name, first_arg, tostring(right), NULL);
                        else
                                print_inst("mul", info.reg_t[i].name, first_arg, second_arg, NULL);
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

                print_inst("sub", "t0", "t0", "t0", NULL);
                print_inst("addi", "t0", "t0", tostring(left), NULL);
                first_arg = "$t0";
        }

        for (i = 2; i < 10; i++)
        {
                if (info.reg_t[i].var == NULL)
                {
                        info.reg_t[i].value = left / right;
                        info.reg_t[i].var = info.all_lines[line_num]->tokens[1];
                        if (first_arg != NULL && second_arg == NULL)
                                print_inst("divi", info.reg_t[i].name, first_arg, tostring(right), NULL);
                        else
                                print_inst("div", info.reg_t[i].name, first_arg, second_arg, NULL);
                        break;
                }
        }
        return (left / right);
}
