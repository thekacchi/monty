#include "monty.h"

/**
 * rotl - function to rotate the stack to the top
 * @stack: the stack
 * @line_num: the line number
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	int lastvalue;

	(void)line_num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	lastvalue = (*stack)->n;

	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}

	current->n = lastvalue;
}
