#include "headers/main.h"

/**
 * add - add two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int add(int right, int left)
{
	printf("sub $t0 $t0 $t0\n"
			"addi $t0 $t0 %d\n"
			"sub $t1 $t1 $t1\n"
			"addi $t1 $t1 %d\n"
			"add $t2 $t0 $t1\n\n", right, left);
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
	printf("sub $t0 $t0 $t0\n"
			"addi $t0 $t0 %d\n"
			"sub $t1 $t1 $t1\n"
			"addi $t1 $t1 %d\n"
			"sub $t2 $t0 $t1\n\n", right, left);
	return (right - left);
}
