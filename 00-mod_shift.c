#include "headers/main.h"

/**
 * mod - mod two numbers
 * @right: first number
 * @left: second number
 * Return: result
 */
int mod(int right, int left)
{
	printf("sub $t0, $t0, $t0\n"
			"addi $t0, $t0, %d\n"
			"sub $t1, $t1, $t1\n"
			"addi $t1, $t1, %d\n"
			"mod $t2, $t0, $t1\n\n", right, left);
	return (right % left);
}

/**
 * shift_left - shift left a number
 * @right: first number
 * @left: second number
 * Return: result
 */
int shift_left(int right, int left)
{
	printf("sub $t0, $t0, $t0\n"
			"addi $t0, $t0, %d\n"
			"sll $t2, $t0, %d\n\n", right, left);
	return (right << left);
}

/**
 * shift_right - shift right a number
 * @right: first number
 * @left: second number
 * Return: result
 */
int shift_right(int right, int left)
{
	printf("sub $t0, $t0, $t0\n"
			"addi $t0, $t0, %d\n"
			"slr $t2, $t0, %d\n\n", right, left);
	return (right >> left);
}
