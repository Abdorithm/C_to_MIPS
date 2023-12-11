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

typedef struct line_s
{
	size_t size;
	char **tokens;
} line_t;

/**
 * struct info_s - ...
 * @reg_s: Stack-allocated array for registers of type s
 * @reg_a: Stack-allocated array for registers of type a
 * @reg_t: Stack-allocated array for registers of type t
 * @reg_v: Stack-allocated array for registers of type v
 * @zero: Register $ZERO
 *
 * @reg_name: name of the register to return it's array
 * Description: The structure of various MIPS registers
 */
typedef struct info_s
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
void put_in_register(char *namevar, int value, char reg_name);
reg *get_reg(char reg_name);
size_t get_argv(void);
char *slice_token(char **token);
int count_tokens(const char *str, const char *del);
int expr_check(char ch);
char *tostring(int number);
void free_2d(char **array);
expr_t *fill_linked_list(char **expression);
void print_list(expr_t *head);
int do_priority(instruction_t opst[], expr_t *head);
void free_node(expr_t *node);
void free_list(expr_t *head);
void overview(void);
void credits(void);
void malloc_failed(void);
void free_all(void);
void add_line(void);

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
