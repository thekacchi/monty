#ifndef __MAIN__
#define __MAIN__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack/queue
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element if the stack (or queue)
 *
 * Description: doubly linked list node stricture
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle opcide
 *
 * Description: opcode and its func for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

void stack_loop(FILE *file, stack_t **stack);

void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

void freeStack(stack_t *stack);
void monty_exit(FILE *file, stack_t *stack);


#endif
