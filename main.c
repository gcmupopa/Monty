#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main()- check code
 * @argc: parameter
 * @argv: parameter
 * Return: a value
 */

int main(int argc, char *argv[])
{
	char *filepath = argv[1];
	FILE *file;
	char *bline = NULL;
	size_t len = 0;
	int value, linum = 0;
	char *opcode = NULL, *vastr = NULL;
	stack_t *stak = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filepath, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}

	while (getline(&bline, &len, file) != -1)
	{
		linum++;
		opcode = strtok(bline, " \t\n");
		if (opcode == NULL || strlen(opcode) == 0)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			vastr = strtok(NULL, " \t\n");
			if (vastr == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", linum);
				free(bline);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			value = atoi(vastr);
			push(&stak, value);
		}

		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stak);
		}

		else
		{
			fprintf(stderr, "L%d unknown instruction %s\n", linum, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(bline);
	fclose(file);
	exit(EXIT_FAILURE);
	return (0);
}
