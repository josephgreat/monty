#ifndef MONTY_H
#define MONTY_H

#define DELIM " \n\t\a"
#define STACK 0
#define QUEUE 1

extern char *op_tok[3];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representaion of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*error_handlers*/
void instruction_err(unsigned int, char *);
void usage_err(void);
void file_err(char *);
void malloc_err(void);
void func_err(unsigned int, char *);

/*operation_handlers*/
void exec_monty(FILE *);
void (*get_op_func(char *))(stack_t **, unsigned int);

/*operation_functions*/

/*1-op_funcs*/
void push(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);

/*2-op_funcs*/
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void divide(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/*3-op_funcs*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*4-op_funcs*/
void set_mode(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
stack_t *init_node(int);

/*utils*/
void parse_token(char *);
int is_empty(char *);
int validatedArg(char *);

/*memory management*/
void free_stack(stack_t **);

#endif
