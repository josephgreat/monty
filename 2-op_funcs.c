#include "monty.h"

/**
 * add - adds the top two elements in a stack,
 * replaces the second with the sum and removes the first
 * @head: stack head
 * @line_number: line number of operation
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
 * @line_number: line number of operation
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

/**
 * mul - multiplies the top two elements in a stack,
 * replaces the second with the product and removes the first
 * @head: stack head
 * @line_number: line number of operation
 * Return: nothing
 */

void mul(stack_t **head, unsigned int line_number)
{
	int product;
	stack_t *nextNode;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't mul, stack too short");

	nextNode = (*head)->next;
	product = (*head)->n * nextNode->n;
	nextNode->n = product;
	free(*head);
	*head = nextNode;
}


/**
 * divide - divides the second top element by the top element in a stack,
 * replaces the second with the quotient and removes the first
 * @head: stack head
 * @line_number: line number of operatioin
 * Return: nothing
 */

void divide(stack_t **head, unsigned int line_number)
{
	int quotient;
	stack_t *nextNode;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't div, stack too short");

	nextNode = (*head)->next;
	quotient = nextNode->n / (*head)->n;
	nextNode->n = quotient;
	free(*head);
	*head = nextNode;
}


/**
 * mod - computes the remainder of the division of the top two elements
 * in a stack, replaces the second with the remainder and removes the first
 * @head: stack head
 * @line_number: line number of operation
 * Return: nothing
 */

void mod(stack_t **head, unsigned int line_number)
{
	int remainder;
	stack_t *nextNode;

	if (!*head || !(*head)->next)
		func_err(line_number, "can't add, stack too short");

	nextNode = (*head)->next;
	remainder = nextNode->n % (*head)->n;
	nextNode->n = remainder;
	free(*head);
	*head = nextNode;
}
