#include "main.h"

/**
 * freeStack - frees memory in the stack
 * @stack: the stack
 */
void freeStack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}

}

/**
 * monty_exit - close file, free memory and exit with EXIT_FAILURE
 * @file: file to be closed
 * @stack: typedef to be freed
 * return: void
 */
void monty_exit(FILE *file, stack_t *stack)
{
	fclose(file);
	freeStack(stack);
	exit(EXIT_FAILURE);
}
