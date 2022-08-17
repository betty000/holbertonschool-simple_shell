#include "main.h"
/**
 * parse_line - Parses the command line looking for commands and argumements.
 * This function it is also in charged of freeing memory that is not longer
 * needed by the program.
 * @line: A pointer to a string. Will always be NULL upon function entry.
 * @size: A holder for numbers of size_t. Will always be initilized to 0.
 * @command_counter: A counter keeping track of how many commands have been
 * entered into the shell.
 * @av: Name of the program running the shell  ?????????
 */
void parse_line(char *line, size_t size, int command_counter, char **av)
{
	int i;
	ssize_t read_len; /*data type*/
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	read_len = getline(&line, &size, stdin); /*we get the lenght of the line*/
	if (read_len != -1) /*condition to creat array*/
	{
		param_array = token_interface(line, delim, token_count); /*array calls the function token, that separate the arguments*/
		if (param_array[0] == NULL) /*if array is null free array with function*/
		{
			single_free(2, param_array, line);
			return;
		}
		i = built_in(param_array, line); /*?*/
		if (i == -1)
			create_child(param_array, line, command_counter, av); /**/
		for (i = 0; param_array[i] != NULL; i++) /*free the array, need to be free all the positions*/
			free(param_array[i]);
		single_free(2, param_array, line); /*free array with function*/
	}
	else
		exit_b(line); /*?*/
}

/**
 * create_child - Creates a child in order to execute another program.
 * @param_array: An array of pointers to strings containing the possible name
 * of a program and its parameters. This array is NULL terminated.
 * @line: The contents of the read line.
 * @count: A counter keeping track of how many commands have been entered
 * into the shell.
 * @av: Name of the program running the shell
 */
void create_child(char **param_array, char *line, int count, char **av)
{
	pid_t id; /*data type*/
	int status;
	int i;
	int check;
	struct stat buf;
	char *tmp_command;
	char *command;

	id = fork(); /*make a call to the father to run the next code at the same time*/
	if (id == 0)
	{
		tmp_command = param_array[0];
		command = path_finder(param_array[0]); /*?*/
		if (command == NULL) /*?*/
		{
			/*Looking for file in current directory*/
			check = stat(tmp_command, &buf); /*?*/
			if (check == -1)
			{
				error_printing(av[0], count, tmp_command); /*print message error*/
				print_str(": not found", 0);
				single_free(2, line, tmp_command); /*free with function*/
				for (i = 1; param_array[i]; i++) /*free the array, need to be free all the positions*/
					free(param_array[i]);
				free(param_array); /*needed?*/
				exit(100); /*?*/
			}
			/*file exist in cwd or has full path*/
			command = tmp_command;
		}
		param_array[0] = command;
		if (param_array[0] != NULL)
		{
			if (execve(param_array[0], param_array, environ) == -1) /*replace the program for the one with the filename, use the variable that point to vector*/
				exec_error(av[0], count, tmp_command); /*print exec error*/
		}
	}
	else
		wait(&status);
	return (0)
}

/**
 * token_interface - Meant to interact with other token functions, and make
 * them more accessible to other parts of the program.
 * @line: A string containing the raw user input.
 * @delim: A constant string containing the desired delimeter to tokenize line.
 * @token_count: the amount of tokens in a string.
 * Return: Upon success an array of tokens representing the command. Otherwise
 * returns NULL.
 */
char **token_interface(char *line, const char *delim, int token_count)
{
	char **param_array;

	token_count = count_token(line, delim); /*identify number of tokens (argumets)*/
	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}
	param_array = tokenize(token_count, line, delim); /*divide the string into the arguments (tokens)*/
	if (param_array == NULL)
	{
		free(line);
		return (NULL);
	}

	return (param_array);
}

/**
 * tokenize - Separates a string into an array of tokens.
 * @token_count: An integer representing the amount of tokens in the array.
 * @line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success a NULL terminated array of pointer to strings.
 * Otherwise returns NULL.
 */
char **tokenize(int token_count, char *line, const char *delim)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = _strdup(line);
	buffer = malloc(sizeof(char *) * (token_count + 1)); /*include the null?*/
	if (buffer == NULL)
		return (NULL);
	token = strtok(line_cp, delim); /*?*/
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * count_token - Counts tokens in the passed string.
 * @line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */
int count_token(char *line, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = _strdup(line);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
