#include "headers/main.h"

/**
 * mul - mul two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int mul(int right, int left)
{
	printf("lw $t0 %d\nlw $t1 %d\nmul $t2 $t0 $t1\n", right, left);
	return (right * left);
}
