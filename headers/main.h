#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct reg_s
{
    char *name;
    int value;
    char *var;
}  reg;

typedef struct all_reg
{
    reg reg_s[8];
    reg reg_a[4];
    reg reg_t[10];
    reg reg_v[2];
    reg zeroo;
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

void readline(char *content, unsigned int counter, FILE *file);
void put_in_register(char *namevar, char *rightside);
char **get_argv(char *strRead);
char **get_argv(char *strRead);

/*Opration*/
int calc(char *rightside);

int add(int right, int left);
/*int mins(int right, int left);
int mul(int right, int left);
int div(int right, int left);
int mod(int right, int left);
int ssl(int right, int left);
int ssr(int right, int left);*/

#endif