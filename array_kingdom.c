#include "main.h"
/**
 * array_kingdom - guarda strigns en un array
 *
 * @line: string que nos pasen
 *
 * Return: Array de strings
 */
int count_strings(char *line)
{
	int count = 0;
	char *input, *line_copy = strdup(line);

	input = strtok(line_copy, " \n\t");
	while (input != NULL)
	{
		count++;
		input = strtok(NULL, " \n\t");
	}
	return (count);
}
char **array_kingdom(char *line)
{
	char *input;
	int i = 1, count = 0;
	char **guardado = NULL;

	count = count_strings(line);
	guardado = malloc(sizeof(char*) * (count + 1));
	if (guardado == NULL)
	{
		return (NULL);
	}
	input = strtok(line, " \n\t");
	guardado[0] = input;
	while (input != NULL)
	{
		input = strtok(NULL, " \n\t");
		guardado[i] = input;
		i++;
	}
	guardado[i] = NULL;
	return (guardado);
}
