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

	if (line_copy == NULL)
		return (0);
	input = strtok(line_copy, " \n\t");
	while (input != NULL)
	{
		count++;
		input = strtok(NULL, " \n\t");
	}
	free(line_copy);
	return (count);
}
char **array_kingdom(char *line)
{
	char *input, *line_copy = strdup(line);
	int i = 0, count = 0;
	char **guardado = NULL;

	if (line == NULL || line_copy == NULL)
		return (NULL);

	count = count_strings(line_copy);
	if (count == 0)
	{
		free(line_copy);
		return (NULL);
	}	
	guardado = malloc(sizeof(char*) * (count + 1));
	if (guardado == NULL)
	{
		free(line_copy);
		return (NULL);
	}
	input = strtok(line_copy, " \n\t");
	while (input != NULL) 
	{
		guardado[i] = strdup(input);
		if(guardado[i] == NULL)
		{
			while(i > 0)
			{
				i--;
				free(guardado[i]);
			}
			free(guardado);
			free(line_copy);
			return (NULL);
		}
		i++;
		input = strtok(NULL, " \n\t");
	}
	guardado[i] = NULL;
	free(line_copy);
	return (guardado);
}
