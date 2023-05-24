#ifndef MONTY_H_
#define MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>


/**
 * struct ProgramContext - variables -args, file, line content
 * @value: represents a value or argument
 * @input_file: a pointer to monty file
 * @instructionString: represents the content of a line
 * @stackMode: a flag that indicates stack or queue mode
 *
 * Description: holds and pass around variables and flags used in the program
 */
typedef struct ProgramContext
{
	char *value;
	FILE *input_file;
	char *instructionString;
	int stackMode;
} ExecutionContext;


extern ExecutionContext executionContext;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* PROTOTYPE DEFINATIONS */


/* instructions_executor.c */
void custom_push(stack_t **list_head, unsigned int number);
void custom_pall(stack_t **list_head, unsigned int number);
void custom_pint(stack_t **list_head, unsigned int number);
void custom_pop(stack_t **list_head, unsigned int lineNumber);
void custom_swap(stack_t **list_head, unsigned int lineNumber);


/* instructions_executor1.c */
void custom_add(stack_t **list_head, unsigned int lineNumber);
void custom_nop(stack_t **list_head, unsigned int lineNumber);
void custom_sub(stack_t **list_head, unsigned int lineNumber);
void custom_div(stack_t **list_head, unsigned int lineNumber);
void custom_mul(stack_t **list_head, unsigned int lineNumber);


/* instructions_executor2.c */
void custom_mod(stack_t **list_head, unsigned int lineNumber);
void custom_pchar(stack_t **list_head, unsigned int lineNumber);
void custom_pstr(stack_t **list_head, unsigned int lineNumber);
void custom_rotl(stack_t **list_head, unsigned int lineNumber);
void custom_rotr(stack_t **list_head,
		__attribute__((unused)) unsigned int lineNumber);


/* instructions_executor3.c */
void custom_stack(stack_t **list_head, unsigned int lineNumber);
void custom_queue(stack_t **list_head, unsigned int lineNumber);


/* instructions_processor.c */
int processInstruction(stack_t **list_head, unsigned int lineNumber,
		char *instructionString, FILE *input_file);
void free_stack(stack_t *list_head);
void pushStack(stack_t **list_head, int new);
void pushQueue(stack_t **list_head, int new);


#endif /* MONTY_H_ */
