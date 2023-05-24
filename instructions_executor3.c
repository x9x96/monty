#include "monty.h"


/**
 * custom_stack - Q15a function that prints the top
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_stack(stack_t **list_head, unsigned int lineNumber)
{
	/* The lineNumber parameter is not used in this function,*/
	/* so the (void) cast is used to suppress compiler warnings*/
	/* about an unused variable*/
	(void)list_head;
	(void)lineNumber;

	/* Set the executionContext.stackMode variable to 0,*/
	/*indicating stack operation*/
	executionContext.stackMode = 0;
}


/**
 * custom_queue - Q15b opcode that sets format of data to a queue (FIFO)
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_queue(stack_t **list_head, unsigned int lineNumber)
{

	/* The lineNumber parameter is not used in this function,*/
	/* so the (void) cast is used to suppress compiler warnings*/
	/* about an unused variable*/
	(void)list_head;
	(void)lineNumber;

	/* Set the executionContext.stackMode to indicate queue mode*/
	executionContext.stackMode = 1;
}
