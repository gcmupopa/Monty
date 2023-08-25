#include "monty.h"

/**
 * swap()- swaps nodes
 * @stak: parameter
 * @linum: parameter
 * Return: nothing
 */

void swap(stack_t **stak, unsigned int linum)
{
	int tempo;
	if (*stak == NULL || (*stak)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linum);
		exit(EXIT_FAILURE);
	}

	tempo = (*stak)->n;
	(*stak)->n = (*stak)->next->n;
	(*stak)->next->n = tempo;
}
