#include <stdio.h>
#include <unistd.h>
int main(int ac, char **av, char **env)
{
	int status, i = 0, j = 0;
	char * token, token2, p = " ", d = ":", line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	pid_t child_pidi;

	while(1)
	{
		printf("$ ");
		read = getline(line, len, stdin);
		if (read == -1)
			printf("No such file or directory");
		token = strtok(line, p);
		token2 = strtok(printenv, d);
		// llamar a la funcion que compara y pasarle token y token2
		while (token[i]) // recorrer token 1
		{
			while (token2[j]) // recorrer token 2
			{
				if (token[i] == token2[j]) // verificamos si el primer argumento es valido
				{
					if (token[i + 1]) // Tiene que verificar qeu el siguiente argumento sea valido
					{
						if // el argumento i + 1 es valido
						else // el argumento i + 1 no sea valido
					}
					else
					{
						// fork + wait + execve
						child_pid = fork();
						if (child_pid == -1)
							perror("Error:");
						if (child_pid == 0)
						{
							// caso del hijo (ejecutar)	
							execve(token2[j]
						}
						else
							// caso de padre (esperar y ejecutar)
							wait(&status);
					}
				}
				else
					printf("No such file or directory");
			j++;
			}
		i++;
		}
	}
}
int comparar_opciones(void)
