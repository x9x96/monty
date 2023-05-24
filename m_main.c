#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE

ExecutionContext executionContext = {NULL, NULL, NULL, 0};

/**
 * main - process instructions from a file in the Monty programming language
 * @arg_c: counts arguments passed to the program
 * @arg_v: access command-line arguments passed to the program
 * desc: reads a file, line by line, and passes each line to the
 * processInstruction function for further processing. It also
 * performs error handling and memory management
 *
 * Return: 0 (success)
 */
int main(int arg_c, char *arg_v[])
{
	char *instructionString;
	FILE *input_file;
	size_t newSize = 0;
	ssize_t newReadLine = 1;
	stack_t *newStack = NULL;
	unsigned int idx = 0;

	if (arg_c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	input_file = fopen(arg_v[1], "r");

	executionContext.input_file = input_file;
	if (!input_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_v[1]);
		exit(EXIT_FAILURE);
	}
	while (newReadLine > 0)
	{
		instructionString = NULL;
		newReadLine = getline(&instructionString, &newSize, input_file);
		executionContext.instructionString = instructionString;
		idx++;
		if (newReadLine > 0)
			processInstruction(&newStack, idx, instructionString, input_file);

		free(instructionString);
	}
	free_stack(newStack);
	fclose(input_file);
	return (0);
}
