#include "main.h"

/**
 * cd_b - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @line: A string representing the input from the user.
 */
void cd_b(char *line)
{
	int index;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	param_array = token_interface(line, delim, token_count);
	if (param_array[0] == NULL)
	{
		single_free(2, param_array, line);
		return;
	}
	if (param_array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5); /*change working directory*/
	}    /*compare if 0 is that is equal*/
	else if (_strcmp(param_array[1], "-") == 0) 
		print_str(param_array[1], 0);

	else
		chdir(param_array[1]); /*change working directory*/
	double_free(param_array);
}

/**
 * env_b - Prints all the environmental variables in the current shell.
 * @line: A string representing the input from the user.
 */
void env_b(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_b - Exits the shell. After freeing allocated resources.
 * @line: A string representing the input from the user.
 */
/*void exit_b(char *line)
{
	free(line);
	exit(0);
	
}*/

/**
 * _atoi - looks for numbers of a string and converts
 * them into integers.
 * @s: pointer to the string to be iterated
 * Return: the number and sign of an array, 0 if no number.
 */
int _atoi(char *s)
{
	int array;
	int sign;
	int num;
	int out;

	num = 0;
	sign = 0;
	out = 0;
	for (array = 0; s[array] != '\0'; array++)
	{
		if (s[array] == '-')
		{
			sign++;
		}
		if (s[array] >= 48 && s[array] <= 57)
		{
			num = num * 10 - (s[array] - '0');
			out = 1;
		}
		else if (out == 1)
		{
			break;
		}
	}
	if ((sign - 1) % 2 != 0)
		num = num * -1;
	return (num);
}

void exit_b(char *line)
{
	int status = 0, i;

	if (line[1] == NULL)
	{
		free(line[0]);
		free(line);
		fflush(stdout);
		exit(status);
	}

	for (i = 0; line[1][i] != '\0'; i++)
	{
		if (line[1][i] < 48 || line[1][i] > 57)
			return (3);
	}
	status = _atoi(line[1]);
	free(line[0]);
	free(line);
	exit(status);

/**
 * check_built_ins - Finds the right function needed for execution.
 * @str: The name of the function that is needed.
 * Return: Upon sucess a pointer to a void function. Otherwise NULL.
 */
void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].built != NULL; i++)
	{
		if (_strcmp(str, buildin[i].built) == 0)
		{
			return (buildin[i].f);
		}
	}
	return (NULL);
}

/**
 * built_in - Checks for builtin functions.
 * @command: An array of all the arguments passed to the shell.
 * @line: A string representing the input from the user.
 * Return: If function is found 0. Otherwise -1.
 */
int built_in(char **command, char *line)
{
	void (*build)(char *);

	build = check_built_ins(command[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", command[0]) == 0)
		double_free(command);
	build(line);
	return (0);
}
