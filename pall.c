#include "monty.h"

/**
 * pall()- prints all data in stack
 * @stak: parameter
 * Return: nothing
 */

void pall(stack_t **stak)
{
	stack_t *curent = *stak;

	if (*stak == NULL)
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}

	else
	{
		while (curent != NULL)
		{
			printf("%d\n", curent->n);
			curent = curent->prev;
		}
	}
}
