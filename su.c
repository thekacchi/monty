#include "monty.h"

/**
 * sub - subtracts the tip element from the second top element
 * of the stack
 * @stack: the stack
 * @line_num: line number
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_num);
}
