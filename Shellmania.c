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
	int status, i = 0, j = 0;
	char * token, token2, p = " ", line = NULL;
	size_t len = 0;
	ssize_t read = 0;

	while(1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			break;
		}
		token = strtok(line, p);
		if (token == NULL)
			continue;
		else
		{

		// Hacemos stat
			if // token existe en el path (nos pasaron la direccion completa)
			{
				// fork + wait + execeve (pasandole los argumentos (flags))
			}
			else // si stat no retorno succes chequeamos si esta en el path manualmente
			{
				if // Encontramos en el path token agregandola despues de cada dir eje: bin/ls, perro/ls, kkk/ls, etc
                                        	// fork + wait + execeve (pasandole los argumentos (flags))???????????????????????????
				else // Si no se encuentra en el path el comando
				     perror(no encontre el comando pa)
			}
		}
	}
}
