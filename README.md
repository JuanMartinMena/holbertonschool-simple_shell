# <h1 align="center"> Shellmania </h1>

## **¿Qué es la shell?**
Es un programa que tiene la capacidad de interpretar comandos(inputs) y dependiendo de que se ingrese, ejecuta el comando(si se encuentra en el path)
o informa que hubo un error(si no esta en el path).

## **Objetivo del proyecto:**
El objetivo del proyecto es replicar el funcionamiento de la SH(shell/terminal) con algunas de sus funcionalidades.

## **Funcionalidades implementadas:**
* Lectura de input: Casos -> Exit, Ctrl+D, dirección completa del path, recorre el path. 
* Reconocimiento de errores.
* Lecctura de pipelines.
* 0 Memory Leaks (Valgrind).

## **Como ejecutar Shellmania.c**
Descargar los archivos (_getenv.c, array_kingdom.c, Shellmania.c, Recorrer_el_path.c, f_w_e.c y main.h).
Una vez descargados ejecutar en la terminal "**./output**".

***Ejemplos de uso:***
* Comando de compilación
![image](https://github.com/user-attachments/assets/db76fffc-60fd-4d23-96f6-230ce0582c5b)
* Archivos utilizados
![image](https://github.com/user-attachments/assets/460b3ed3-c46d-4a80-8581-ecee37c52875)
* Comando de ejecución
![image](https://github.com/user-attachments/assets/063f9e86-4b1e-49ba-aa78-99e19b802bbc)
* Comando **"ls -la"**
![image](https://github.com/user-attachments/assets/ca1e3df0-6b88-4c55-a07f-04262f65f573)
* Caso **Ctrl + D**
![image](https://github.com/user-attachments/assets/2137e6a3-aa69-4888-b3ad-6ccefd3f7fb4)
* Caso **"as"**
![image](https://github.com/user-attachments/assets/c191b875-bdfb-47c1-ab3d-a1b6cb7df73b)
* Creación de archivos
![image](https://github.com/user-attachments/assets/eb13fd88-c30e-4228-9925-4ac6cfea9937)
![image](https://github.com/user-attachments/assets/1298210c-6b1b-491c-b5b1-893bb177b13a)
![image](https://github.com/user-attachments/assets/5eadf585-94d2-4dc1-980a-d53026ed1fe9)
* Caso de se ruta completa
![image](https://github.com/user-attachments/assets/818a5997-d33e-4b42-9a91-2b9cc6fa8a59)
* Caso de **error**
![image](https://github.com/user-attachments/assets/5a5decdf-2634-46ea-88bc-2ba71136c4a3)
* Caso de **enter**
![image](https://github.com/user-attachments/assets/6268819e-cc3c-42bd-9a39-5663336c507a)
* Caso de **espacio** "_"
![image](https://github.com/user-attachments/assets/891b72f5-8c53-40cb-9b11-03dc1c5daa2e)
* Caso **tab** **"\t"**
![image](https://github.com/user-attachments/assets/05465e22-6b0c-417b-8cda-baba24188031)
* Caso **no interactivo**
![image](https://github.com/user-attachments/assets/cf94648c-971d-4f80-b3fb-cb777eed4475)

# <h2 align="left"> Objetivos de las funciones: </h2>

* **shellmania.c ->** Funcion principal (Main) que llama a las demas funciones para
interpretar comandos o errores.
```
int main(int ac, char **av, char **env);
Return fail = NULL;
Return success = String;
```
* **_getenv.c ->** Identifica el PATH dentro de la variable de entorno (environment).
```
char *_getenv(const char *name);
Return fail = NULL;
Return success = String;
```
* **array_kingdom.c ->** Tokeniza el input. Con un delimitador seleccionado recorre
  el input y lo guarda enarray de strings.
```
char **array_kingdom(char *line);
Return fail = NULL;
Return success = Array de punteros a strings;
```

* **follow_the_path.c ->** Agrega el input al final de cada ruta del PATH y comprueba
  que existe.
```
char *Recorrer_el_path(char *input);
Return fail = NULL;
Return success = PATH;
```
* **f_w_e.c ->** Hace el proceso de fork(duplica el proceso), wait(espera a que termine un
  proceso para ejecutar el otro) y exceve(remplaza el codigo actual por el codigo del
  input si existe y lo ejecuta).
```
int f_w_e(char *pathname, char *argv[], char *envp[]);
Return fail = -1;
Return success = 0;
```
* **_perror.c ->** Le da un mensaje de error al caso de que no se encuentre el input en el PATH.
```
void *_perror(char *s, int counter, char *l);
Return = void(Error message);
```
* **main.h ->** Header(contiene los prototipos de todas las funciones).

# <h3 align="left">Flowcharts: </h3>

### main.c
![Diagrama sin título drawio](https://github.com/user-attachments/assets/7fcd8353-4571-40ca-85a6-7e2da549fb0a)

## count_strings.c && array_kingdom.c
![array_kingdom c drawio](https://github.com/user-attachments/assets/10ac0814-44df-484c-9289-ac9f11ea37ee)

## f_w_e.c
![FWE drawio](https://github.com/user-attachments/assets/7db1b679-0442-4023-9e3f-411fc403d2f4)

## Recorrer_el_path.c
![Diagrama sin título drawio (1)](https://github.com/user-attachments/assets/4ef64cce-f34b-49a8-87ec-60c60a5d9cfc)
