![alt text](https://github.com/nicolas1897/holbertonschool-simple_shell/blob/main/simple%20shell-general.drawio.png)

# Project Simple Shell
### Holberton School 

## Synopsis

Program that works as an interface, it takes commands from the user by the keyboard and gives them to the kernel, operating system to perform, execute the programs related. 

## Description

The simple shell takes a line and use strtok() function to create arrays of the commands (tokens); for that, the main function calls parse_line(), and also this last one calls token_interface() and built_in(), if there is necessary it calls create_child().

The token_interface() function calls count_token(), that contain the number of tokens, and tokenizen(), that create the array of tokens with the strtock() function, returning the array of commands.

The built_in() function select and apply the function related to the command that was identified. The functions that are going to be used are:

* cd_b(): change working directory
* env_b(): print environmental variables
* exit_b(): free allocate resources and exit shell

To work the built_in() function calls check_built_ins(), that select from a list the function.

The create_child() function identify the path and guive an error message; for that, it calls path_finder(), that finds the path of a program. The last function mentioned calls:

* find_path(): find an index of enviromental variable
* search_directories(): look for a file in path directories
* build_path(): combine command and directory

There are necesary other functions to make work the ones described before:

* str_len(): lenght of a string
* double_free(): free double pointer variables
* single_free(): free pointers of a string
* error_printing(): print an error message
* exec_error(): print exec error
* _strcmp(): compare 2 strings
* _strdup(): duplicate a string
* print_str(): print a string
* _write_char(): print char
* print_number(): print a number

## Requirements

* Compiled on Ubuntu 20.04 LTS
* Compile code with: "gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh"
* Include the "main.h" header file in main program.

## Example

```
$ ./shell_0.3
=> /bin/lswait.c
simple_shell.c analize_funtions.c pathing.c builtins.c helper_functions.c print_number.c secondary_functions.c 
exec    fork    mypid   ppid   printenv  promptc  shell shell_0.3  wait
```

## Testing

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## AUTHORS
* Maria Echeverria
* Nicolas Cuevas
