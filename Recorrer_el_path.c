#include "main.h"
/**
 * Recorrer_el_path - Busca un archivo en los directorios del PATH
 *
 * @input: El nombre del archivo a buscar
 *
 * Return: La ruta completa del archivo si se encuentra o 1 si falla
 */
char *Recorrer_el_path(char *input)
{
	const char *path = getenv("PATH");
	size_t input_len, path_len, super_path_len;
	char *super_path, *path_copy, *token2;
	struct stat sb;

	if (path == NULL)
		return (NULL);
	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (NULL);
	strcpy(path_copy, path);
	token2 = strtok(path_copy, "=");
	token2 = strtok(NULL, "=");
	token2 = strtok(path_copy, ":");
	while (token2 != NULL)
	{
		input_len = strlen(input);
		path_len = strlen(token2);
		super_path_len = path_len + input_len + 2;
		super_path = malloc(super_path_len);
		if (super_path == NULL)
		{
			perror("No hay pa vo");
			free(path_copy);
			return (NULL);
		}
		strcpy(super_path, token2);
		strcat(super_path, "/");
		strcat(super_path, input);
		if (stat(super_path, &sb) != -1)
		{
			free(path_copy);
			return (super_path);
		}
		else
			free(super_path);
		token2 = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
