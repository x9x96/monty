#include "monty.h"


/**
 * custom_mod - Q9 opcode that performs the modulus expression on the stack
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_mod(stack_t **list_head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
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
	/* Compute the sum of the top two elements in the stack*/
	tem_val = head->next->n % head->n;
	/* Update the value of the second element with the modulus*/
	head->next->n = tem_val;
	/* Move the list_head pointer to the next element in the stack*/
	*list_head = head->next;
	free(head);
}


/**
 * custom_pchar - Q11 opcode that prints the char at the top of the stack,
 * followed by a new line
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_pchar(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *h;

	h = *list_head;

	/* If the stack is empty*/
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}

	/* If the value is out of the valid ASCII range*/
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		fclose(executionContext.input_file);
		free(executionContext.instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}

	/* Print the character corresponding to the value*/
	printf("%c\n", h->n);
}


/**
 * custom_pstr - Q12 opcode that prints the string starting at the
 * top of the stack
 * followed by a new
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_pstr(stack_t **list_head, unsigned int lineNumber)
{
	stack_t *head;

	/* The lineNumber parameter is not used in this function,*/
	/* so the (void) cast is used to suppress compiler warnings*/
	/* about an unused variable*/
	(void)lineNumber;

	head = *list_head;

	while (head != NULL)
	{
		if (head->n <= 0 || head->n > 127)
			break;

		printf("%c", head->n);
		head = head->next;
	}

	printf("\n");
}


/**
 * custom_rotl- Q13 opcode that rotates the stack to the top
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_rotl(stack_t **list_head,
		__attribute__((unused)) unsigned int lineNumber)
{
	stack_t *new_head;
	stack_t *tem_val = *list_head;

	tem_val = *list_head;

	/* If the stack is empty or contains only one element*/
	/* no rotation is needed*/
	if ((*list_head)->next == NULL || *list_head == NULL)
		return;

	new_head = (*list_head)->next;
	new_head->prev = NULL;

	/* Traverse to the last node of the stack*/
	while (tem_val->next != NULL)
		tem_val = tem_val->next;

	/* Make the last node point to the original head*/
	tem_val->next = *list_head;
	(*list_head)->next = NULL;
	(*list_head)->prev = tem_val;
	(*list_head) = new_head;
}


/**
 * custom_rotr - Q14 opcode that rotates the stack to the bottom
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 *
 * Return: nil
 */
void custom_rotr(stack_t **list_head,
		__attribute__((unused)) unsigned int lineNumber)
{
	stack_t *last_node;

	last_node = *list_head;

	if ((*list_head)->next == NULL || *list_head == NULL)
		return;

	while (last_node->next)
		last_node = last_node->next;

	last_node->next = *list_head;

	/* Update the next pointer of the second-to-last node to NULL*/
	last_node->prev->next = NULL;
	last_node->prev = NULL;

	/* Update the previous pointer of the current head to the last node*/
	(*list_head)->prev = last_node;
	(*list_head) = last_node;
}
