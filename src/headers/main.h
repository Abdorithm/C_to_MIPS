#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/* defines */
#define notUsed __attribute__((unused))
#define RESET       "\033[0m"

#define RED         "\033[38;2;136;8;8m"
#define GREEN       "\033[38;2;8;136;8m"
#define BLUE        "\033[38;2;8;8;136m"
#define YELLOW      "\033[38;2;136;136;8m"
#define MAGENTA     "\033[38;2;136;8;136m"
#define CYAN        "\033[38;2;8;136;136m"
#define WHITE       "\033[38;2;220;220;220m"
#define BLACK       "\033[38;2;8;8;8m"
#define ORANGE      "\033[38;2;255;165;0m"
#define PURPLE      "\033[38;2;128;0;128m"
#define PINK        "\033[38;2;255;105;180m"
#define TEAL        "\033[38;2;0;128;128m"
#define LIME        "\033[38;2;0;255;0m"
#define BROWN       "\033[38;2;139;69;19m"
#define OLIVE       "\033[38;2;128;128;0m"
#define INDIGO      "\033[38;2;75;0;130m"
#define MAROON      "\033[38;2;128;0;0m"

#define LIGHTRED    "\033[38;2;255;102;102m"
#define DARKRED     "\033[38;2;139;0;0m"
#define LIGHTGREEN  "\033[38;2;102;255;102m"
#define DARKGREEN   "\033[38;2;0;100;0m"
#define LIGHTBLUE   "\033[38;2;102;178;255m"
#define DARKBLUE    "\033[38;2;0;0;139m"
#define LIGHTYELLOW "\033[38;2;255;255;153m"
#define LIGHTMAGENTA "\033[38;2;255;153;255m"
#define LIGHTCYAN   "\033[38;2;153;255;255m"
#define GRAY        "\033[38;2;128;128;128m"
#define LIGHTGRAY   "\033[38;2;192;192;192m"
#define DARKGRAY    "\033[38;2;64;64;64m"
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
	size_t (*f)(size_t num_line);
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
	int j_jumper;
	int k_jumper;
	int loop_jumper;
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
	int (*f)(char *left_s, char *right_s, size_t line_num);
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
expr_t *do_priority(instruction_t opst[], expr_t *head, size_t line_num);
void free_node(expr_t *node);
void free_list(expr_t *head);
void overview(void);
void credits(void);
void ascii(void);
void malloc_failed(void);
void free_all(void);
void add_line(void);
size_t decision(size_t line);
void print_inst(char *inst, char *reg1, char *reg2, char *imd, char *num);
void fake_int(size_t line);

/* Conditions */
int check_numbers_condtions(size_t line_num);
size_t condition(size_t line_num);
size_t if_condition(size_t line_num);
void print_condition(int eql, char *a, char *b,
		char *symbol, int loop_or_condition);
size_t else_or_elseif_condition(size_t line_num, int count_condtions);
reg return_reg(char *name);
int valid_int(char *str);

/* Operations */

size_t calc(size_t line_number);

int add(char *left_s, char *right_s, size_t line_num);
int sub(char *left_s, char *right_s, size_t line_num);
int mul(char *left_s, char *right_s, size_t line_num);
int divs(char *left_s, char *right_s, size_t line_num);
int mod(char *left_s, char *right_s, size_t line_num);
int shift_right(char *left_s, char *right_s, size_t line_num);
int shift_left(char *left_s, char *right_s, size_t line_num);

void prev_temps(char **first_arg, char **second_arg, char *left_s, char *right_s, int *left, int *right);

void assign_args(char **first_arg, char **second_arg, int right, int left);

/*Loops*/
size_t for_loop(size_t line_num);
size_t while_loop(size_t line_num);
void preprocess(char *name, int num);
void count_loop_tokens(size_t line_num, int *init, int *cond, int *increament);


#endif
