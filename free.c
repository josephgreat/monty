#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - frees a stack
 * @stack: stack to be freed
 * Return: nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
