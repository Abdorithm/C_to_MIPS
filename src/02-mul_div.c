#include "headers/main.h"

/**
 * mul - mul two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int mul(int right, int left)
{
	printf("sub $t0 $t0 $t0\n"
			"addi $t0 $t0 %d\n"
			"sub $t1 $t1 $t1\n"
			"addi $t1 $t1 %d\n"
			"mul $t2 $t0 $t1\n\n", right, left);
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
	int res;

	res = right / left;
	printf("sub $t0 $t0 $t0\n"
			"addi $t0 $t0 %d\n"
			"sub $t1 $t1 $t1\n"
			"addi $t1 $t1 %d\n"
			"div $t2 $t0 $t1\n\n", right, left);
	return (res);
}
