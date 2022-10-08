#include "monty.h"

/**
 * parse_token - gets the commands and arguments in each line in the file
 * @line: current line in file
 * Return: nothing
 */

void parse_token(char *line)
{
	int toklen = 0;
	char *token;

	token = strtok(line, DELIM);
	while (token != NULL && toklen < 2)
	{
		*(op_tok + toklen) = token;
		token = strtok(NULL, DELIM);
		toklen++;
	}
}

/**
 * validatedArg - validates an argument passed to the command and
 * converts it to an integer
 * @arg: op_tok argument to be checked
 * Return: NULL on failure else the converted integer
 */

int validatedArg(char *arg)
{
	int i = 0;

	while (arg[i])
	{
		if (arg[i] == '-')
		{
			i++;
			continue;
		}
		else if (toupper(arg[i]) != tolower(arg[i]))
			return (-1);
		else if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (atoi(arg));
}

/**
 * is_empty - checks if a line is empty
 * @line: line to be checked
 * Return: -1 if empty else 1
 */

int is_empty(char *line)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; DELIM[j]; j++)
		{
			if (line[i] == DELIM[j])
				break;
		}
		if (DELIM[j] == '\0')
			return (1);
	}
	return (-1);
}
