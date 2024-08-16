#include "main.h"
/**
 * array_kingdom - guarda strigns en un array
 *
 * @line: string que nos pasen
 *
 * Return: Array de strings
 */
char **array_kingdom(char *line)
{
	char *input;
	int i = 1, input_len = 0;
	char **guardado = NULL;
	// primero es armar el array de arrays
	guardado = malloc(sizeof(char*) * 1024);
	input = strtok(line, " \n");
	guardado[0] = input;
	while (input != NULL)
	{
		input = strtok(NULL, " \n");
		guardado[i] = input;
		i++;
	}
	guardado[i] = NULL;
	return (guardado);
}
