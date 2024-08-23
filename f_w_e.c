#include "main.h"
/**
 * f_w_e - Esta funcion hace el proceso fork + wait + execve
 *
 * @pathname: Ruta completa del programa a ejecutar en el nuevo proceso
 * @argv: Argumentos del progrema a ejecutar (array of strings)
 * @envp: Variables de entorno para el nuevo proceso (array of strings)
 *
 * Return: 0 si el proceso se ejecuta bien, -1 si se ejecuta mal
 */
int f_w_e(char *pathname, char *argv[], char *envp[])
{
	pid_t child_pidi;
	int status;

	child_pidi = fork();
	if (child_pidi == 0)
	{
		execve(pathname, argv, envp);
		perror("execve fallo");
		return (-1);
	}
	else if (child_pidi > 0)
	{
		wait(&status);
		return (WIFEXITED(status));
	}
	else
	{
		return (-1);
	}
	return (0);
}
