#include "monty.h"

/**
 * pop - implement pop opscode
 * @stack: the stack
 * @line_num: line numbers
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * swap - function to swap top two elements of stack
 * @stack: the stack
 * @line_num: the number line
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - function to add the top two elements of the stack
 * @stack: the stack
 * @line_num: the line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	if (*stack ==NULL || (*stack)->next ==NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_num);
}

/**
 * nop - function does nothing
 * @stack: the stack
 * @line_num: line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
