#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

char *op_tok[3] = {NULL, NULL, "stack"};

/**
 * main - checks code
 * @av: argument list
 * @ac: argument count
 * Return: EXIT_FAILURE on failure else EXIT_SUCCESS
 */

int main(int ac, char **av)
{
	FILE *montyfile;

	if (ac != 2)
		usage_err();

	montyfile = fopen(av[1], "r");
	if (montyfile == NULL)
		file_err(av[1]);

	exec_monty(montyfile);

	fclose(montyfile);
	exit(EXIT_SUCCESS);
}
