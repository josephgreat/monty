#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @head: head stack
 * @line_number: line number of current operation
 * Return: nothing
 */

void pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
		func_err(line_number, "can't pchar, stack empty");

	if ((*head)->n < 0 || (*head)->n > 127)
		func_err(line_number, "can't pchar, value out of range");

	fprintf(stdout, "%c\n", (*head)->n - 48 + '0');
}


/**
 * pstr - prints the string starting at the top of the stack
 * @head: head stack
 * @line_number: line number of current operation
 * Return: nothing
 */

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	while (current)
	{
		if (current->n == 0)
			break;
		if (current->n < 0 || current->n > 127)
			break;

		fprintf(stdout, "%c", current->n - 48 + '0');
		current = current->next;
	}

	fprintf(stdout, "\n");

	(void)line_number;
}


/**
 * rotl - rotates the stack to the top
 * @head: head stack
 * @line_number: line number of current operation
 * Return: nothing
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int top;

	top = (*head)->n;

	while (current->next)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = top;

	(void)line_number;
}


/**
 * rotr - rotates the stack to the bottom
 * @head: head stack
 * @line_number: line number of current operation
 * Return: nothing
 */

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int bottom;

	while (current->next)
		current = current->next;

	bottom = current->n;

	while (current->prev)
	{
		current->n = current->prev->n;
		current = current->prev;
	}
	current->n = bottom;

	(void)line_number;
}
