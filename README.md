![alt text](https://github.com/nicolas1897/holbertonschool-simple_shell/blob/main/simple%20shell-general.drawio.png)

# Project Simple Shell
### Holberton School 

## Synopsis

Program that works as an interface, it takes commands from the user by the keyboard and gives them to the kernel, operating system to perform, execute the programs related. 

## Description

The simple shell takes a line and use strtok() function to create arrays of the commands (tokens); for that, the main function calls parse_line(), and also this last one calls token_interface() and built_in().

The token_interface() function calls count_token(), that contain the number of tokens, and tokenizen(), that create the array of tokens with the strtock() function, returning the array of commands.



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
