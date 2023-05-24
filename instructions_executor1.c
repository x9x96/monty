#include "monty.h"


/**
 * custom_add - Q4 opcode that adds the top two elements of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_add(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;
	int tem_val;
	int size;

	head = *list_head;

	/* Calculate the size of the stack by traversing it*/
	for (size = 0; head != NULL ; size++)
		head = head->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}

	/* Reset the head pointer to the current stack head*/
	head = *list_head;
	/* Compute the sum of the top two elements in the stack*/
	tem_val = head->n + head->next->n;
	/* Update the value of the second element with the sum*/
	head->next->n = tem_val;
	/* Move the list_head pointer to the next element in the stack*/
	*list_head = head->next;
	free(head);
}


/**
 * custom_nop - Q5 opcode that doesn’t do anything
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_nop(stack_t **list_head, unsigned int lineNumber)
{
	/* The lineNumber parameter is not used in this function,*/
	/* so the (void) cast is used to suppress compiler warnings*/
	/* about an unused variable*/
	(void) lineNumber;
	(void) list_head;
}


/**
 * custom_sub - Q6 opcode that subtracts the top element of the stack
 * from the second top element of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_sub(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *tem_val;
	int size = 0;
	int difference;

	tem_val = *list_head;

	/* Calculate the size of the stack by traversing it*/
	while (tem_val)
	{
		tem_val = tem_val->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	tem_val = *list_head;
	/* Compute the difference of the second and first elements in the stack*/
	difference = tem_val->next->n - tem_val->n;
	/* Update the value of the second element with the difference*/
	tem_val->next->n = difference;
	/* Move the list_head pointer to the next element in the stack*/
	*list_head = tem_val->next;
	free(tem_val);
}


/**
 * custom_div - Q7 opcode that divides the second top element of the
 * stack by the top element of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_div(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;
	int tem_val;
	int size;

	head = *list_head;
	/* Calculate the size of the stack by traversing it*/
	for (size = 0; head != NULL ; size++)
		head = head->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	head = *list_head;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	/* Compute the division of the top two elements in the stack*/
	tem_val = head->next->n / head->n;
	/* Update the value of the second element with the division*/
	head->next->n = tem_val;
	/* Move the list_head pointer to the next element in the stack*/
	*list_head = head->next;
	free(head);
}


/**
 * custom_mul - Q8 opcode that multiplies the second top element of the
 * stack with the top element of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_mul(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;
	int tem_val;
	int size;

	head = *list_head;

	/* Calculate the size of the stack by traversing it*/
	for (size = 0; head != NULL ; size++)
		head = head->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	head = *list_head;
	/* Compute the multiplication of the top two elements in the stack*/
	tem_val = head->next->n * head->n;
	/* Update the value of the second element with the multiplication*/
	head->next->n = tem_val;
	/* Move the list_head pointer to the next element in the stack*/
	*list_head = head->next;
	free(head);
}
