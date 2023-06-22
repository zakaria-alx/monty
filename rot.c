#include "monty.h"

/**
  *fn_rotr- rotates the stack to the bottom
  *@head: stack's head
  *@line_number: line_number
  *Return: no return
 */
void fn_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
  *fn_rotl- rotates the stack to the top
  *@head: stack's head
  *@line_number: line_number
  *Return: no return
 */
void fn_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
