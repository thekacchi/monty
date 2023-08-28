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

/**
 * rotr - function to rotate tge stack to the bottom
 * @stack: thge stack
 * @line_num: line number
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->prev->next = NULL;
	current->prev->next = *stack;
	(*stack)->prev = current;
	*stack = current;

	(void)line_num;
}
