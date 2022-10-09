#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * get_op_func - get the operation function to be performed
 * based on the opcode
 * @opcode: opcode for function comparism
 * Return: operation function
 */

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		/*{"rotl", rotl},*/
		/*{"rotr", rotr},*/
		{"nop", nop},
		{"#", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);

	return (NULL);
}

/**
 * exec_monty - executes the monty file
 * @montyfile: monty file to be executed
 * Return: nothing
 */

void exec_monty(FILE *montyfile)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	int nread = 0;
	unsigned int line_number = 0;
	void (*op_func)(stack_t**, unsigned int);


	while ((nread = getline(&line, &len, montyfile)) != -1)
	{
		line_number++;
		if (is_empty(line) == -1)
			continue;

		parse_token(line);

		if (op_tok[0] && op_tok[0][0] == '#')
			strcpy(op_tok[0], "#");


		op_func = get_op_func(op_tok[0]);
		if (op_func == NULL)
			instruction_err(line_number, op_tok[0]);

		op_func(&stack, line_number);

		op_tok[0] = NULL;
		op_tok[1] = NULL;
	}
	free_stack(&stack);
	free(line);
}
