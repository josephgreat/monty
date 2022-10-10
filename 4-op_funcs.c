#include "monty.h"

/**
 * set_mode - changes the mode of data structure
 * @head: stack head
 * @line_number: line number of operation
 * Return: nothing
 */

void set_mode(stack_t **head, unsigned int line_number)
{
	if (strcmp(op_tok[0], "queue") == 0)
	{
		op_tok[2] = "queue";
		return;
	}
	op_tok[2] = "stack";

	(void)head;
	(void)line_number;
}


/**
 * nop - does nothing in the stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * init_node - initializes a new node
 * @n: integer for the new node
 * Return: new node
 */
stack_t *init_node(int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
		malloc_err();

	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return (newNode);
}
