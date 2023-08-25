#include "main.h"

/**
 * main - main entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char buffer[1024], *token;
	unsigned int line_num = 0;
	int value;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2) {
		fprintf(stderr, "USAGE: monty file\n");
		freeStack(stack);
		return (EXIT_FAILURE);
	}

	if (file == NULL) {
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
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
				monty_exit(file, stack);
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
		else if (strcmp(token, "swap") == 0)
			swap(&stack, line_num);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token);
			monty_exit(file, stack);
		}
	}
	fclose(file);
	freeStack(stack);
	return (EXIT_SUCCESS);
}
