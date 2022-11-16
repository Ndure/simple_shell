#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status, i = 0, j = 5;
	pid_t child_pid;

	while (j--)
	{
		i++;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(1);
		}
		if (child_pid == 0)
		{
			printf("iteration %d:\n", i);
			sleep(2);
			execve(argv[0], argv, NULL);
			perror("execve failed");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	printf("\n\n%d\n", status);

	return (0);
}
