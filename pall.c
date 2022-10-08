#include "monty.h"
#include <stdio.h>

/**
 * pall - prints all elements in a stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
/*printf("palll\n");	*/
	if (!head)
		return;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
