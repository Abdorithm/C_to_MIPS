#include "main.h"

/**
 * sub - sub two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int sub(int right, int left)
{
	printf("lw $t0 %d\nlw $t1 %d\nsub $t2 $t0 $t1\n", right, left);
	return (right - left);
}
