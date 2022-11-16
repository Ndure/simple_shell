#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char **get_input(char *input)
{
	char **command;
	char *parsed;
	int i = 0;
	char *buf = malloc(sizeof(input));

	while (input[i] != '\n')
	{
		buf[i] = input[i];
		i++;
	}
	buf[i] = '\0';

	command = malloc(sizeof(char *) * 64);
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	parsed = strtok(buf, " ");

	i = 0;
	while (parsed != NULL)
	{
		command[i] = parsed;
		i++;
		parsed = strtok(NULL, " ");
	}
	command[i] = NULL;

	return (command);
}

int main(int argc, char *argv[], char *envp[])
{
	char *lineptr;
	ssize_t nread;
	size_t len = 0;
	pid_t child_pid;
	char **commands;
	int status;

	(void)argc;
	(void)argv;

	while (1)
	{
		write (1, "\ncisfun$ ", 9);
		nread = getline(&lineptr, &len, stdin);
		if (nread == -1)
		{
			free(lineptr);
			write(1, "\nexit\n", 6);
			exit(0);
		}

		commands = get_input(lineptr);
		if (commands[0] == NULL)
		{
			free(commands);
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(commands[0], commands, envp);
			/* if execve fails */
			perror(commands[0]);
			exit(1);
		}
		else
		{
			wait(&status);
		}
		free(commands);
	}
	return (0);
}
