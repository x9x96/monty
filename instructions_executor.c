#include "monty.h"


/**
 * custom_push - Q0a opcode that pushes an element to the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_push(stack_t **list_head, unsigned int lineNumber)
{
	int has_error = 0;
	int s = 0;
	int idx;

	if (executionContext.value)
	{
		if (executionContext.value[0] == '-')
		{
			s++;
		}
		for ( ; executionContext.value[s] != '\0'; s++)
		{
			if (executionContext.value[s] < 48 || executionContext.value[s] > 57)
				has_error = 1;
		}
		if (has_error == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(executionContext.input_file);
			free(executionContext.instructionString);
			free_stack(*list_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	idx = atoi(executionContext.value);
	if (executionContext.stackMode == 0)
	{
		pushStack(list_head, idx);
	}
	else
		pushQueue(list_head, idx);
}


/**
 * custom_pall - Q0b opcode that prints all the values on the stack,
 * starting from the top of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_pall(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;

	/* The lineNumber parameter is not used in this function,*/
	/* so the (void) cast is used to suppress compiler warnings*/
	/* about an unused variable*/
	(void)lineNumber;

	/* Set the head pointer to the current stack head*/
	head = *list_head;

	/* If the stack is empty return without printing anything*/
	if (head == NULL)
	{
		return;
	}

	/* Print the values of all elements in the stack*/
	for ( ; head != NULL; head = head->next)
		printf("%d\n", head->n);
}


/**
 * custom_pint - Q1 opcode that prints the value at the top of the
 * stack, followed by a new line
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_pint(stack_t **list_head, unsigned int lineNumber)
{
	if (*list_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}

	/* Print the value of the top element in the stack*/
	printf("%d\n", (*list_head)->n);
}


/**
 * custom_pop - Q2 opcode that removes the top element of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_pop(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;

	if (*list_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}

	/* Reset the head pointer to the current stack head*/
	head = *list_head;

	/* Move the list_head pointer to the next element in the stack*/
	*list_head = head->next;
	free(head);
}


/**
 * custom_swap - Q3 function that swaps the top two elements of the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_swap(stack_t **list_head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	/* Reset the head pointer to the current stack head*/
	head = *list_head;

	/* Swap the values of the top two elements in the stack*/
	tem_val = head->n;
	head->n = head->next->n;
	head->next->n = tem_val;
}
