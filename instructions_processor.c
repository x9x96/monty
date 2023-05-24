#include "monty.h"

/**
 * processInstruction - processes and execute the opcode instructions
 * @list_head: head of linked list stack
 * @lineNumber: track of the current position of input being read
 * @instructionString: pointer to a character array or string
 * representing content to be processed
 * @input_file: a pointer to FILE structure representing file stream
 *
 * Return: nil
 */
int processInstruction(stack_t **list_head, unsigned int lineNumber,
		char *instructionString, FILE *input_file)
{
	instruction_t instructions[] = {
	{"pop", custom_pop},		{"swap", custom_swap},	{"add", custom_add},
	{"nop", custom_nop},		{"sub", custom_sub},		{"div", custom_div},
	{"mul", custom_mul},		{"mod", custom_mod},		{"pchar", custom_pchar},
	{"pstr", custom_pstr},	{"rotl", custom_rotl},	{"rotr", custom_rotr},
	{"queue", custom_queue},	{"stack", custom_stack},	{"push", custom_push},
	{"pall", custom_pall},	{"pint", custom_pint},	{NULL, NULL}
	};

	char *opcode;
	unsigned int idx = 0;

	opcode = strtok(instructionString, " \n\t");

	if (opcode && opcode[0] == '#')
	{
		return (0);
	}

	executionContext.value = strtok(NULL, " \n\t");

	while (instructions[idx].opcode && opcode)
	{
		if (strcmp(opcode, instructions[idx].opcode) == 0)
		{
			instructions[idx].f(list_head, lineNumber);
			return (0);
		}
		idx++;
	}

	if (opcode && instructions[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		fclose(input_file);
		free(instructionString);
		free_stack(*list_head);
		exit(EXIT_FAILURE);
	}
	return (1);
}


/**
 * free_stack - function that frees a doubly linked list
 * @list_head: head of linked list stack
 *
 * Return: nil
 */
void free_stack(stack_t *list_head)
{
	stack_t *tem_val;

	tem_val = list_head;

	/* Traverse the linked list and free each node*/
	while (list_head)
	{
		/* Store the next node in the temporary value*/
		tem_val = list_head->next;

		/* Free the current node*/
		free(list_head);

		/* Move to the next node*/
		list_head = tem_val;
	}
}


/**
 * pushStack - adds a new element to the top of a stack
 * @list_head: head of linked list stack
 * @new: new value
 *
 * Return: nil
 */
void pushStack(stack_t **list_head, int new)
{
	stack_t *tem_val;
	stack_t *new_node;

	tem_val = *list_head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	/* Update the previous pointer of the current list head if it exists*/
	if (tem_val != NULL)
	{
		tem_val->prev = new_node;
	}

	/* Set the value of the new node to the given value*/
	new_node->n = new;

	/* Update the next and previous pointers of the new node*/
	new_node->next = *list_head;
	new_node->prev = NULL;
	/* Set the new node as the new list head*/
	*list_head = new_node;
}


/**
 * pushQueue -  adds a new node to the end of queue
 * @list_head: head of the queue
 * @new: new value
 *
 * Return: nil
 */
void pushQueue(stack_t **list_head, int new)
{
	stack_t *tmp_val;
	stack_t *new_node;

	tmp_val = *list_head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = new;
	new_node->next = NULL;
	if (tmp_val)
		/* Traverse to the last node of the list*/
		while (tmp_val->next)
		{
			tmp_val = tmp_val->next;
		}

	if (!tmp_val)
	{
		*list_head = new_node;
		new_node->prev = NULL;
	}

	else
	{
		tmp_val->next = new_node;
		new_node->prev = tmp_val;
	}
}
