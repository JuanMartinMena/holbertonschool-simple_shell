#include "main.h"

/**
 * free_array - Libera el espacio que ocupa un array de punteros
 *
 * @array: array a liberar
 *
 * Return: array liberado
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
/**
 * main - interpreta comandos simples
 *
 * @env: Array de strings que contine las variables de entorno del programa
 * @ac: void
 * @av: void
 * Return: return 0 if end
 */
int main(__attribute__((unused))int ac,
	 __attribute__((unused))char **av,
	 char **env)
{
	char *path, *line = NULL, *s = "sh", *a;
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int counter = 0, status = 0;
	char **arr = NULL;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		arr = array_kingdom(line);
		if (arr == NULL)
			continue;
		if (strcmp(arr[0], "exit") == 0)
			free_array(arr), free(line), exit(status);
		if (strcmp(arr[0], "env") == 0)
			print_array(env);
		else
		{
			if (stat(arr[0], &sb) != -1)
				status = f_w_e(arr[0], arr, NULL);
			else
			{
				path = follow_the_path(arr[0]);
				if (path == NULL)
					a = _perror(s, counter, line), free(a);
				else
					status = f_w_e(path, arr, NULL), free(path);
			}

		}
		free_array(arr);
	}
	free(line);
	return (status);
}
/**
 * _perror - mensaje de error
 *
 * @s: string "sh"
 * @counter: numero de comandos ejecutados
 * @l: input pasado
 *
 * Return: mensaje de error
 */
char *_perror(char *s, int counter, char *l)
{
	char *a;

	l[strcspn(l, "\n")] = 0;
	a = malloc(sizeof(char *) * strlen(s) + strlen(l) + sizeof(int) + 5);
	sprintf(a, "%s: %i: %s ", s, counter, l);
	perror(a);
	return (a);
}
/**
 * print_array - printea un array de punteros a strings
 *
 * @array: array de punteros a strings
 *
 * Return: El mismo array pero habiendo printeado el contenido
 *
 */
char **print_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{

		printf("%s\n", array[i]);
		i++;
	}
	return (array);
}
