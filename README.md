![alt text](https://github.com/nicolas1897/holbertonschool-simple_shell/blob/main/simple%20shell-specific.drawio.png)

# Project Printf
### Holberton School 

## Synopsis

This function prints, acording to a format, the arguments received from the user.

## Description

The _printf() function receive arguments and print them, when the function apply the condition related to the character of the list that is after the symbol '%', that is the one that will be search with the analyzer() function, will call the funtions to print the next type of data:

* c: Print a character
* s: Print a string
* %: Print the character '%'
* d: Print a number
* i: Print an integer

## Requirements

* Compiled on Ubuntu 20.04 LTS
* Compile code with: "gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c" or "gcc *.c"
* Include the "main.h" header file to use the _printf() function in your main file.

## Example

```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
     int len;
     unsigned int ui;
     void *addr;

     len = _printf("Let's try to printf a simple sentence.\n");
     _printf("Length:[%d, %i]\n", len, len);
     _printf("Negative:[%d]\n", -762534);
     len = _printf("Percent:[%%]\n");
     _printf("String:[%s]\n", "I am a string !");
     _printf("Character:[%c]\n", 'H');
}
```

## Testing

```
$./_printf
Let's try to printf a simple sentence.
Length:[39, 39]
Negative:[-762534]
Percent:[%]
String:[I am a string !]
Character:[H]
$
```
## AUTHORS
* Maria Echeverria
* Luiyi Hurtado
* Nicolas Cuevas
