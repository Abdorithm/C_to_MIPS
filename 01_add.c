#include "main.h"

/**
 * add - add two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int add(int right, int left)
{
	printf("lw $t0 %d\nlw $t1 %d\nadd $t2 $t0 $t1\n", right, left);
	return (right + left);
}
