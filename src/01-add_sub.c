#include "headers/main.h"

/**
 * add - add two numbers
 * @left_s: first number
 * @right_s: second number
 * @line_num: line number
 *
 * Return: result
 */
int add(char *left_s, char *right_s, size_t line_num)
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
                        info.reg_t[i].value = left + right;
                        info.reg_t[i].var = info.all_lines[line_num]->tokens[1];
                        if (first_arg == NULL && second_arg != NULL)
                                print_inst("addi", info.reg_t[i].name, second_arg, tostring(left));
                        else if (first_arg != NULL && second_arg == NULL)
                                print_inst("addi", info.reg_t[i].name, first_arg, tostring(right));
                        else
                                print_inst("add", info.reg_t[i].name, first_arg, second_arg);
                        break;
                }
        }
        return (left + right);
}

/**
 * sub - sub two numbers
 * @left_s: first number
 * @right_s: second number
 * @line_num: ...
 * Return: result
 */
int sub(char *left_s, char *right_s, size_t line_num)
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

                print_inst("sub", "t0", "t0", "t0");
                print_inst("addi", "t0", "t0", tostring(left));
                first_arg = "$t0";
        }

        for (i = 2; i < 10; i++)
        {
                if (info.reg_t[i].var == NULL)
                {
                        info.reg_t[i].value = left - right;
                        info.reg_t[i].var = info.all_lines[line_num]->tokens[1];
                        if (first_arg != NULL && second_arg == NULL)
                                print_inst("subi", info.reg_t[i].name, first_arg, tostring(right));
                        else
                                print_inst("sub", info.reg_t[i].name, first_arg, second_arg);
                        break;
                }
        }
        return (left - right);
}
