#include "monty.h"

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
		func_err(line_number, "usage: push integer");

	newNode->n = validatedArg(op_tok[1]);
	newNode->prev = NULL;
	if (!head)
		newNode->next = NULL;
	else
		newNode->next = *head;

	*head = newNode;
	/*printf("Pushed\n");*/
}

/**
 * swap - swaps the top two elements in a stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void swap(stack_t **head, unsigned int line_number)
{
	int temp_num;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't swap, stack too short");

	temp_num = (*head)->next->n;
	(*head)->next->n = (*head)->n;
	(*head)->n = temp_num;
}


