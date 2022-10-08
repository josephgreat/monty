#include "monty.h"

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

/**
 * pint - prints the first element in a stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!current)
		func_err(line_number, "can't pint, stack empty");

	fprintf(stdout, "%d\n", current->n);
}

/**
 * pop - prints all elements in a stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	
	if (!*head)
		func_err(line_number, "can't pop an empty stack");

	temp = (*head)->next;
	free(*head);
	*head = temp;
}


