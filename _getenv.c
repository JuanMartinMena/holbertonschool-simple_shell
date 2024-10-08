#include "main.h"
/**
 * _getenv - funcion para extraer el path de las variables de entorno
 *
 * @name: el string "path"
 *
 * Return: el contenido del path
 *
 */
char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_len = strlen(name);
	char *equal_sign;
	size_t var_name_len;

	while (*env != NULL)
	{
		equal_sign = strchr(*env, '=');
		if (equal_sign == NULL)
		{
			env++;
			continue;
		}
		var_name_len = equal_sign - *env;
		if (var_name_len == name_len && strncmp(*env, name, name_len) == 0)
		{
			return (equal_sign + 1);
		}
		env++;
	}
	return (NULL);
}
