#include "main.h"

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
	printf("lw $t0 %d\nlw $t1 %d\ndiv $t2 $t0 $t1\n", right, left);
	return (res);
}
