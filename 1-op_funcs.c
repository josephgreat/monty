#include "monty.h"

/**
 * push - adds an element to a stack
 * @head: head stack
 * @line_number: current line of command
 * Return: nothing
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	stack_t *newNode;

	if (op_tok[1] == NULL || validatedArg(op_tok[1]) == -1)
		func_err(line_number, "usage: push integer");

	newNode = init_node(validatedArg(op_tok[1]));
	
	if (strcmp(op_tok[2], "stack") == 0)
	{
		if (*head)
		{
			newNode->next = *head;
			(*head)->prev = newNode;
		}
		*head = newNode;
	}
	else
	{
		if (!*head)
		{
			*head = newNode;
			return;
		}

		while (current->next)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
	}
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


/**
 * pall - prints all elements in a stack
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

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
