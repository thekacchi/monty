#include "main.h"

/**
 * stack_loop - processes instructions
 * @file: contains instructions
 * @stack: the stack
 */
void stack_loop(FILE *file, stack_t **stack)
{
	char buffer[1024], *token;
	unsigned int line_num = 0;
	int value;
	
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_num++;
		token = strtok(buffer, " \t,\n");

		if (token == NULL || token[0] == '#')
			continue; /** skip empty likes & comments **/
		else if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				monty_exit(file, *stack);
			}
			value = atoi(token);
			push(&stack, value);
		}
		else if (strcmp(token, "pall") == 0)
			pall(&stack, line_num);
		else if (strcmp(token, "pint") == 0)
			pint(&stack, line_num);
		else if (strcmp(token, "pop") == 0)
			pop(&stack, line_num);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token);
			monty_exit(file, stack);
		}
	}

}
