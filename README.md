# <h1 align="center"> Shellmania </h1>

## **What is the shell?**
It is a program that can interpret commands (inputs), and depending on what is entered, it either executes the command (if found in the path) or 
reports an error (if it is not in the path).

## **Project Objective:**
The objective of the project is to replicate the functionality of SH (shell/terminal) with some of its features.

## **Implemented Features:**
* Input reading: Cases -> Exit, Ctrl+D, full path, path traversal.
* Error recognition.
* Pipeline reading.
* 0 Memory Leaks (Valgrind).

## **How to run shellmania.c**
Download the files (_getenv.c, array_kingdom.c, shellmania.c, follow_the_path.c, f_w_e.c, and main.h). Once downloaded, run in the terminal 
with "./output".

***Usage Examples:***
* Compilation command
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
* Files used
![image](https://github.com/user-attachments/assets/460b3ed3-c46d-4a80-8581-ecee37c52875)
* Execution command
![image](https://github.com/user-attachments/assets/063f9e86-4b1e-49ba-aa78-99e19b802bbc)
* Command "ls -la"
![image](https://github.com/user-attachments/assets/ca1e3df0-6b88-4c55-a07f-04262f65f573)
* Ctrl + D case
![image](https://github.com/user-attachments/assets/2137e6a3-aa69-4888-b3ad-6ccefd3f7fb4)
* "as" case
![image](https://github.com/user-attachments/assets/c191b875-bdfb-47c1-ab3d-a1b6cb7df73b)
* File creation
![image](https://github.com/user-attachments/assets/eb13fd88-c30e-4228-9925-4ac6cfea9937)
![image](https://github.com/user-attachments/assets/1298210c-6b1b-491c-b5b1-893bb177b13a)
![image](https://github.com/user-attachments/assets/5eadf585-94d2-4dc1-980a-d53026ed1fe9)
* Full path case
![image](https://github.com/user-attachments/assets/818a5997-d33e-4b42-9a91-2b9cc6fa8a59)
* Error case
![image](https://github.com/user-attachments/assets/5a5decdf-2634-46ea-88bc-2ba71136c4a3)
* Enter case
![image](https://github.com/user-attachments/assets/6268819e-cc3c-42bd-9a39-5663336c507a)
* Space case "_"
![image](https://github.com/user-attachments/assets/891b72f5-8c53-40cb-9b11-03dc1c5daa2e)
* Tab case "\t"
![image](https://github.com/user-attachments/assets/05465e22-6b0c-417b-8cda-baba24188031)
* Non-interactive case
![image](https://github.com/user-attachments/assets/cf94648c-971d-4f80-b3fb-cb777eed4475)

# <h2 align="left"> Function Objectives: </h2>

* **shellmania.c ->** Main function that calls other functions to interpret commands or errors.
```
int main(int ac, char **av, char **env);
Return fail = NULL;
Return success = String;
```
* **_getenv.c ->** Identifies the PATH within the environment variable.
```
char *_getenv(const char *name);
Return fail = NULL;
Return success = String;
```
* **array_kingdom.c ->** Tokenizes the input. With a selected delimiter, it traverses the input and stores it in an array of strings.
```
char **array_kingdom(char *line);
Return fail = NULL;
Return success = Array de punteros a strings;
```

* **follow_the_path.c ->** Appends the input to the end of each PATH route and checks its existence.
```
char *follow_the_path(char *input);
Return fail = NULL;
Return success = PATH;
```
* **f_w_e.c ->** Handles the process of fork (duplicates the process), wait (waits for one process to finish before executing another)
* , and execve (replaces the current code with the input code if it exists and executes it).
```
int f_w_e(char *pathname, char *argv[], char *envp[]);
Return fail = -1;
Return success = 0;
```
* **_perror.c ->** Provides an error message when the input is not found in the PATH.
```
void *_perror(char *s, int counter, char *l);
Return = void(Error message);
```
* **main.h ->** Header (contains the prototypes of all functions).

# <h3 align="left">Flowcharts: </h3>

### main.c
![Diagrama sin título drawio](https://github.com/user-attachments/assets/7fcd8353-4571-40ca-85a6-7e2da549fb0a)

## count_strings.c && array_kingdom.c
![array_kingdom c drawio](https://github.com/user-attachments/assets/10ac0814-44df-484c-9289-ac9f11ea37ee)

## f_w_e.c
![FWE drawio](https://github.com/user-attachments/assets/7db1b679-0442-4023-9e3f-411fc403d2f4)

## follow_the_path.c
![Diagrama sin título drawio (1)](https://github.com/user-attachments/assets/4ef64cce-f34b-49a8-87ec-60c60a5d9cfc)

**AUTHORS:** Juan Martín Mena && Luna Leguisamo.
