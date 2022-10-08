#ifndef MONTY_H
#define MONTY_H
#define DELIM " \n\t\a"
extern char *op_tok[2];

#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
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
void push_err(unsigned int);
void pint_err(unsigned int);

/*operation_handlers*/
void exec_monty(FILE *);
void (*get_op_func(char *))(stack_t **, unsigned int);

/*operation_functions*/
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);

/*utils*/
void parse_token(char *);
int is_empty(char *);
int validatedArg(char *);

#endif