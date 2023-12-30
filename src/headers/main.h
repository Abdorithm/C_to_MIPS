#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* defines */
#define notUsed __attribute__((unused))
#define RESET   "\033[0m"
#define RED     "\033[38;2;136;8;8m"      
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
 * struct first_s - this struct determine the process by the first word(string)
 * @first : the first word
 * @f : the fucntion to handle the process(condition , loop, etc)
 * Description: execute the right function
 */

typedef struct first_s
{
	char *first;
	int (*f)(size_t num_line);
} first_t;

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
 * struct info_s - ...
 * @reg_s: Stack-allocated array for registers of type s
 * @reg_a: Stack-allocated array for registers of type a
 * @reg_t: Stack-allocated array for registers of type t
 * @reg_v: Stack-allocated array for registers of type v
 * @zero: Register $ZERO
 * @get_reg: a pointer function so you can access it through info
 * @line_cnt: how many lines are there
 * @j_jumber: count the j_jumber
 * @k_jumber: count the k_jumber
 * @curr_line: current line read
 * @curr_tokens: current tokens
 * @all_lines: all the lines in one place
 * @file: the file we read
 *
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
	int j_jumber;
	int k_jumber;
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
char *tostring(int number);
void free_2d(char **array);
expr_t *fill_linked_list(char **expression);
int expr_check(char ch);
void print_list(expr_t *head);
expr_t *do_priority(instruction_t opst[], expr_t *head);
void free_node(expr_t *node);
void free_list(expr_t *head);
void overview(void);
void credits(void);
void ascii(void);
void malloc_failed(void);
void free_all(void);
void add_line(void);
void decision(size_t line);


/* Conditions */
int check_numbers_condtions(size_t line_num);
int condition(size_t line_num);
int if_condition(size_t line_num);
void print_condtion(size_t line_num, char *a, char *b,
		char *symbol, char *equal_symbol);
size_t else_or_elseif_condition(size_t line_num, int count_condtions);

/* Operations */
int calc(size_t line_number);
int add(int right, int left);
int sub(int right, int left);
int mul(int right, int left);
int divs(int right, int left);
int mod(int right, int left);
int shift_left(int right, int left);
int shift_right(int right, int left);

#endif
