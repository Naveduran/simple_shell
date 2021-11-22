# Shell

This repository contains our own simple version of the shell, a command line interpreter. It was written in C, as a learning exercise. The [Flowchart](https://miro.com/app/board/o9J_lMIftoE=/) shows how the program was built.

## Files of this repository
|File| Description |
|--|--|
| **man_1_simple_shell.1** | It is the manual for using the shell. Contains a description, ways for invocation, and some examples of builtins and executables that can be used inside the command line interpreter.|
| **shell.h** | It is a header file that contains all the c libraries needed for the program, the description and prototypes of all the functions, structures, builtins, printing functions, and helpers.|
| **shell.c** | It contains the entry point of the program, where the execution begins. It shows the prompt and receives the characters written in the command line.|
| **get_line.c** | It gets the string written from the command line and save it in a predefined buffer, allocating enoght space. |
| **str_tok.c** | It cuts the string in parts. |
| **tokenize.c** | It save the parts to be analyzed later. |
| **builtins_list.c** | It compare the command with a list of builtins, and if there is a match, It calls the associated builtin. |
| **builtins.c** | It contains the code of the builtins included in the program.
| **find_in_path.c** |  It analyze the global variable path. |
| **execute.c** | It tries to execute the string as a command. |
| **helpers_string.c** | It contains some functions that help the main functions to process the strings. |
| **helpers_printing.c** | It contains some functions that help to print content in the standar error and the standar output.|

## Compilation

```c
gcc -Wall -Werror -Wextra -pedantic *.c
````

## Example to use it

```c
simple_shell$./a.out
dali<3 ls
README.md
dali<3 exit
simple_shell$
````

## Environment
This project has been tested on `Ubuntu 14.06.6 LTS`

## Authors
* **Natalia Vera:** [GitHub](https://github.com/Naveduran) - [Email](naveduran@gmail.com) - [Twitter](https://twitter.com/NaVeDuran1)
* **Jerson Pérez:** [Github](https://github.com/jepez90/) - [Linkedin](https://www.linkedin.com/in/jerson-p%C3%A9rez-010059a4)
* **Edher Ramírez:** [GitHub](https://github.com/Edheramirez) -[Linkedin](https://www.linkedin.com/in/edher-joe-ramirez-estupi%C3%B1an-5b80701b8/) - [Twitter](https://twitter.com/edhe_r)
