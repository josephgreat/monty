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

		fprintf(stdout, "%c", current->n - 48 + '0');
		current = current->next;
	}

	fprintf(stdout, "\n");

	(void)line_number;
}
