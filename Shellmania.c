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
	char *path, *line = NULL, *s = "sh";
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int comando, i = 0, counter = 0;
	char **xd = NULL;

	(void)av;
	(void)ac;
	(void)env;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		line[strcspn(line, "\n")] = 0;
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(line, "cape") == 0)
			printf("peladito <3\n");
		xd = array_kingdom(line);
		if (xd == NULL)
			continue;
		if (stat(xd[0], &sb) != -1)
		{
			comando = f_w_e(xd[0], xd, NULL);
			if (comando == -1)
				continue;
		}
		else
		{
			path = Recorrer_el_path(xd[0]);
			if (path == NULL)
				_perror(s, counter, line);
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

void *_perror(char *s, int counter, char *l)
{
	char *a;
	a = malloc(sizeof(char*) * strlen(s) + strlen(l) + sizeof(int) + 5);
	sprintf(a,"%s: %i: %s ", s, counter, l);
	perror(a);
	free(a);	
}
