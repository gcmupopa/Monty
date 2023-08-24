#include "monty.h"

/**
 * pint()- check if stack is empty
 * @stak: parameter
 * @linum: parameter
 * Return: nothing
 */

void pint(stack_t **stak, unsigned int linum)
{
	if (*stak == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linum);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stak)->n);
}
