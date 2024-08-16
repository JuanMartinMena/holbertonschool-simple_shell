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
	int comando;

	(void)ac;
	(void)env;
	while(1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			break;
		}
		av = array_kingdom(line);
			
		if (stat(line, &sb) != -1)
		{
			comando = f_w_e(line, av, NULL);
			if (comando)
				continue;
		}
		else
		{
			path = Recorrer_el_path(line);
			if (path == NULL)
			{
			}
			else
				f_w_e(path, av, NULL);
		}
	}
	return (0);
}

