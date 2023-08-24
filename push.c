#include "monty.h"

/**
 * push()- push node on the stack
 * @stak: parameter
 * @value: parameter
 * Return: nothing
 */

void push(stack_t **stak, unsigned int value)
{
	stack_t *nunode;
	nunode = malloc(sizeof(stack_t));
	if (nunode == NULL)
		exit(EXIT_FAILURE);

	nunode->n = value;
	nunode->next = NULL;

	if (*stak == NULL)
	{
		nunode->prev = NULL;
		*stak = nunode;
	}
	else
	{
		nunode->prev = *stak;
		(*stak)->next = nunode;
		*stak = nunode;
	}
}

