#include "monty.h"

/**
 * pop()- removes top elem from stack
 * @stak: parameter
 * @linum: parameter
 * Return: nothing
 */

void pop(stack_t **stak, unsigned int linum)
{
	stack_t *top;
	if (*stak == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linum);
		exit(EXIT_FAILURE);
	}

	top = *stak;
	*stak = top->next;

	if (*stak != NULL)
		(*stak)->prev = NULL;
	
	free(top);
}
