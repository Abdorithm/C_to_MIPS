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

extern all_reg regs;


int main(int argc, char *argv[]);

void readline(char *content, unsigned int counter, FILE *file);
void put_in_register(char *namevar, char *rightside);

#endif


