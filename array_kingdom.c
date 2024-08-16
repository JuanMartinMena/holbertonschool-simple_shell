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
	int i = 0, input_len = 0;
	char **guardado = NULL;

	while (input != NULL)
	{
		input_len = strlen(input);
		guardado[i] = malloc(sizeof(input_len));
		input = strtok(line, " ");
		guardado[i] = input;
		input = strtok(NULL, " ");
		i++;
	}
	return (guardado);
}
