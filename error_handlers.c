#include "monty.h"

/**
 * usage_err - exit on usage error
 * Return: nothing
 */
void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_err - exit on file error
 * @file: file name
 * Return: nothing
 */
void file_err(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}


/**
 * malloc_err - exit on malloc failure
 * Return: nothing
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * instruction_err - exit on invalid instruction
 * @line_num: line number
 * @opcode: invalid operation code
 * Return: nothing
 */
void instruction_err(unsigned int line_num, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}


/**
 * func_err - exit on failure to meet specifications
 * @line_num: line number
 * @err_txt: error text
 * Return: EXIT_FAILURE
 */
void func_err(unsigned int line_num, char *err_txt)
{
	fprintf(stderr, "L%d: %s\n", line_num, err_txt);
	exit(EXIT_FAILURE);
}
