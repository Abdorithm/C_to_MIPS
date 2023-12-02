#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct reg_s - Represents one register
 * @name: name of the data type
 * @value: value of the data type
 * @var: ...
 *
 * Description: The structure of a specific MIPS register
 */
typedef struct reg_s
{
	char *name;
	int value;
	char *var;
} reg;

/**
 * struct all_reg_s - ...
 * @reg_s: Stack-allocated array for registers of type s
 * @reg_a: Stack-allocated array for registers of type a
 * @reg_t: Stack-allocated array for registers of type t
 * @reg_v: Stack-allocated array for registers of type v
 * @zero: Register $ZERO
 *
 * Description: The structure of various MIPS registers
 */
typedef struct all_reg_s
{
	reg reg_s[8];
	reg reg_a[4];
	reg reg_t[10];
	reg reg_v[2];
	reg zero;
}  all_reg;

extern all_reg regs;

/* functions */
void readline(char *content, unsigned int counter, FILE *file);
void put_in_register(char *namevar, char *rightside);
int calc(char *rightside);

#endif


