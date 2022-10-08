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

	if (op_tok[1] == NULL || validatedArg(op_tok[1]) == -1)
		push_err(line_number);

	newNode->n = validatedArg(op_tok[1]);
	newNode->prev = NULL;
	if (!head)
		newNode->next = NULL;
	else
		newNode->next = *head;

	*head = newNode;
	/*printf("Pushed\n");*/
}
