#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", fn_push}, {"pall", fn_pall}, {"pint", fn_pint},
				{"pop", fn_pop}, {"swap", fn_swap}, {"add", fn_add},
				{"nop", fn_nop}, {"sub", fn_sub}, {"div", fn_div},
				{"mul", fn_mul}, {"mod", fn_mod}, {"pchar", fn_pchar},
				{"pstr", fn_pstr}, {"rotl", fn_rotl}, {"rotr", fn_rotr},
				{"queue", fn_queue}, {"stack", fn_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
