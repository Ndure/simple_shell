#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>

char **get_input(char *input)
{
	char **command;
	char *separator = " ";
	char *parsed;
	int i = 0;

	command = malloc(sizeof(char *) * 8);
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	parsed = strtok(input, separator);

	while (parsed != NULL)
	{
		command[i] = parsed;
		i++;
		parsed = strtok(NULL, separator);
	}
	command[i] = NULL;

	return (command);
}

int cd(char *path)
{
	int n;

	if (path == NULL)
	{
		n = chdir("/home/alex/");
		return (n);
	}
	n = chdir(path);
	return (n);
	
}

int main(void)
{
	char **command;
	char *input;
	pid_t child_pid;
	int stat_loc;

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		write(1, "\n", 1);
		input = readline("unixsh> ");
		command = get_input(input);

		if (command[0] == NULL)
			continue;
		if (strcmp(command[0], "exit") == 0)
		{
			write(1, "exit\n", 5);
			free(command);
			free(input);
			exit(0);
		}		
		if (strcmp(command[0], "cd") == 0)
		{
			cd(command[1]);
			perror(command[1]);
			continue;
		}


		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		if (child_pid == 0)
		{
			signal(SIGINT, SIG_DFL);

			execvp(command[0], command);
			/* if execvp fails */
			perror(command[0]);
			exit(1);
		}
		else
		{
			waitpid(child_pid, &stat_loc, WUNTRACED);
		}
		free(input);
		free(command);
	}

	return (0);
}
