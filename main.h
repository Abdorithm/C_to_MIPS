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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */

typedef struct instruction_s
{
	char *opcode;
	int (*f)(int right, int left);
} instruction_t;

extern all_reg regs;

int main(int argc, char *argv[]);

/* functions */
void readline(char *content, unsigned int counter, FILE *file);
void put_in_register(char *namevar, char *rightside);
char **get_argv(char *strRead);

/*Opration*/
int calc(char *rightside);

int add(int right, int left);
int sub(int right, int left);
int mul(int right, int left);
int divs(int right, int left);
int mod(int right, int left);
/*int ssl(int right, int left);*/
/*int ssr(int right, int left);*/

/*Handle if*/
void handel_if(char **tokens_line);



#endif
