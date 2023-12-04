#include "headers/main.h"

/**
 * mod - mod two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */

int mod(int right, int left)
{
	printf("lw $t0 %d\nlw $t1 %d\nmod $t2 $t0 $t1\n", right, left);
	return (right % left);
}