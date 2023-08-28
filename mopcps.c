#include "monty.h"

/** 
 * mod - mod func computes the remainder of the division
 * @stack: the stack
 * @line_ num: the line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_num);
}

/**
 * pchar - pchar func prints the char at the top of the stack
 * @stack: the stack
 * @line_num: the line number
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	int value;

	if (*stack ==NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < -0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');

	pop(stack, line_num);
}

/**
 * pstr - function to print the string starting at the top of the stack
 * @stack: the stack
 * @line_num: line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
	(void)line_num;
}
