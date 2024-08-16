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
	char **xd = NULL;

	(void)av;
	(void)ac;
	(void)env;
	while(1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		line[read] = '\0';
		if (read == -1)
		{
			perror("getline");
			break;
		}
		xd = array_kingdom(line);
		printf("%s\n", xd[0]);
		if (stat(xd[0], &sb) != -1)
		{
			comando = f_w_e(xd[0], xd, NULL);
			if (comando)
				continue;
		}
		else
		{
			printf("aca si?\n");
			path = Recorrer_el_path(xd[0]);
			if (path == NULL)
			{
			}
			else
				f_w_e(path, xd, NULL);
		}
	}
	return (0);
}

