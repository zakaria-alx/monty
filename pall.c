#include "monty.h"

/**
 * fn_pall - ...
 * @head: stack's head
 * @line_number: no used
 * Return: nothing
*/
void fn_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
