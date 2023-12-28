#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* defines */
#define notUsed __attribute__((unused))

/**
 * struct expr_s - doubly linked list
 * @data: value
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * used to navigate through the expression
 */
typedef struct expr_s
{
	char *data;
	struct expr_s *prev;
	struct expr_s *next;
} expr_t;

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
 * struct line_s - store a whole line
 *
 * @size: the number of tokens
 * @tokens: the tokens it self
 */
typedef struct line_s
{
	size_t size;
	char **tokens;
} line_t;

/**
 * struct all_reg_s - ...
 * @reg_s: Stack-allocated array for registers of type s
 * @reg_a: Stack-allocated array for registers of type a
 * @reg_t: Stack-allocated array for registers of type t
 * @reg_v: Stack-allocated array for registers of type v
 * @zero: Register $ZERO
 * @get_reg: a pointer function so you can access it through info
 * @line_cnt: how many lines are there
 * @curr_line: current line read
 * @curr_tokens: current tokens
 * @all_lines: all the lines in one place
 * @file: the file we read
 *
 * Description: The structure of various MIPS registers
 */
typedef struct all_reg_s
{
	reg reg_s[9];
	reg reg_a[5];
	reg reg_t[11];
	reg reg_v[3];
	reg zero;
	reg * (*get_reg)(char);
	size_t line_cnt;
	char *curr_line;
	char **curr_tokens;
	line_t **all_lines;
	FILE *file;

}  info_t;

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

extern info_t info;

/* functions */
void readline(char *content, unsigned int counter);
void put_in_register(char *namevar, int value, char reg_name);
reg *get_reg(char reg_name);
char **get_argv(char *line);
int count_tokens(const char *str, const char *del);
char *tostring(int number);
void free_2d(char **array);
expr_t *fill_linked_list(char **expression);
void print_list(expr_t *head);
int do_priority(instruction_t opst[], expr_t *head);
void free_node(expr_t *node);
void free_list(expr_t *head);

/* Operations */
int calc(char *rightside);
int add(int right, int left);
int sub(int right, int left);
int mul(int right, int left);
int divs(int right, int left);
int mod(int right, int left);
int shift_left(int right, int left);
int shift_right(int right, int left);

#endif
