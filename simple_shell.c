#include "main.h"

/**
 * main - main program of the simple shell
 * @ac: The number of parameters passed to the executable file. In this case
 * this variable will not be used.
 * @av: The name of the program.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, char **av) /*call parse_line*/
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN); /*not able to use keyboard to interrupt*/
	do {
		command_counter++;
		line = NULL; /*is necesary to initialize before calling the function*/
		size = 0; /*is necesary to initialize before calling the function*/
		parse_line(line, size, command_counter, av);

	} while (1);

	return (0);
}
