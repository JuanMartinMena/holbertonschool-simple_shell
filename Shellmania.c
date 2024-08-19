#include "main.h"
/**
 * main - interpreta comandos simples
 *
 * @ac: numero de argumentos pasados al programa
 * @av: Array de strings que contiene los argumentos pasados
 * @env: Array de strings que contine las variables de entorno del programa
 */
int main(int ac, char **av, char **env)
{
	char *path;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int comando, i = 0;
	char **xd = NULL;

	(void)av;
	(void)ac;
	(void)env;
	while(1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			continue;
		xd = array_kingdom(line);
		if (xd == NULL)
			continue;
		if (stat(xd[0], &sb) != -1)
		{
			comando = f_w_e(xd[0], xd, NULL);
			if (comando == -1)
			{
				break;
			}
		}
		else
		{
			path = Recorrer_el_path(xd[0]);
			if (path == NULL)
			{
				break;
			}
			else
				f_w_e(path, xd, NULL);
		free(path);
		}
		while (xd[i] != NULL)
		{
			free(xd[i]);
			i++;
		}
		free(xd);
	}
	free(line);
	return (0);
}
