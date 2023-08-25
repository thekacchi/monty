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
/**	char buffer[1024], *token;
	unsigned int line_num = 0;
	int value; */
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

	stack_loop(file, &stack);

	fclose(file);
	freeStack(stack);
	return (EXIT_SUCCESS);
}
