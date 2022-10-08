#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * push - adds an element to a stack
 * @head: head stack
 * @line_number: current line of command
 * Return: nothing
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
		malloc_err();

	if (validatedArg(op_tok[1]) == -1)
		instruction_err(line_number, op_tok[0]);

	newNode->n = validatedArg(op_tok[1]);
	newNode->prev = NULL;
	if (!head)
		newNode->next = NULL;
	else
		newNode->next = *head;

	*head = newNode;
	/*printf("Pushed\n");*/
}
