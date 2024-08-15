#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(int ac, char **av, char **env)
{
	int status, i = 0, j = 0;
	char * token, token2, p = " ", line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	pid_t child_pidi;

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
		// Antes de stat hacer o tener en cuenta los comandos que no hay que buscar en el path ??????????????????????????
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
		free (line)
	}
}
int Recorrer_el_path(char * input)
{
	const char *path = getenv("PATH"); // Hacemos que path contenga los valores del PATH
	int encontro = 0;
	size_t input_len, path_len, super_path_len;
	char *super_path;
	char *path_copy;

	if (path == NULL)
	{
		perror("No se pudo obtener la variable de entorno PATH");
		return (1);
	}
	path_copy = malloc(strlen(path) + 1); // reserva de memoria para la copia
	if (path_copy == NULL) // falla de reserva de memoria
	{
		perror("Error al asignar memoria");
		return (1);
	}
	strcpy(path_copy, path); // copia el contenido de path a path_copy
	token2 = strtok(path_copy, ":");
	while (token2 != NULL) // se fija en todo el path
	{
		input_len = strlen(input);
		path_len = strlen(token2);
		super_path_len = path_len + input_len + 2;
		super_path = malloc(super_path_len);
		if (super_path == NULL)
		{
			perror("Error al asignar memoria");
			free(path_copy);
			return (1);
		}
		// Reservamos memoria pero esta vacia la cadena
		strcpy(super_path, token2); // nuestra cadena ahora tiene el path
		strcat(super_path, '/'); // despues de la info de el path agregamos una '/'
		strcat(super_path, input); // agregamos el input del usuario a super_path
		// Ahora super_path tiene la info de la "ruta de path/input"
		// Casos
		if (stat(input, super_path, NULL))
		{
			free(path_copy);
			free(super_path);
			return(Funca);
		}
		else
		{
			free(path_copy);
			free(super_path);
		}
	}
}









	if (token2 == NULL)
		perror("Fallo de strtok");
	while(token2[i] != NULL) // recorrer el path
	{
		token_len = (strlen(token) + strlen(token2) + 2); // Calculamos el largo del nuevo path
		super_path = malloc(sizeof(token_len); // reservar espacio del largo de token_len a super_path
		if (super_path == NULL)
		{
			perror();
			return(1);
		}
		//pegamos en super_path el token2 y luego le concatenamos el token (lo que nos pasa el usuario)
		super_path = strdup(token2);
		super_path = strcat(token);
		if (stat(super_path))
			return;
		else
			free(super_path);
		i++;
	}
	perror(no enconte nada pa);
	return;
}

