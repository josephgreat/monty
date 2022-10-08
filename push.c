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

/**
 * add - adds the top two elements in a stack,
 * replaces the second with the sum and removes the first
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void add(stack_t **head, unsigned int line_number)
{
	int sum;
	stack_t *nextNode;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't add, stack too short");

	nextNode = (*head)->next;
	sum = (*head)->n + nextNode->n;
	nextNode->n = sum;
	free(*head);
	*head = nextNode;
}

/**
 * sub - subtracts the top two elements in a stack,
 * replaces the second with the difference and removes the first
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void sub(stack_t **head, unsigned int line_number)
{
	int diff;
	stack_t *nextNode;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't sub, stack too short");

	nextNode = (*head)->next;
	diff = nextNode->n - (*head)->n;
	nextNode->n = diff;
	free(*head);
	*head = nextNode;
}


