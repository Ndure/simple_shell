#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - a program that illustrates how the use of waitpid function in C
 *
 * Return: always 0.
 */
int main(void)
{
	pid_t child_pid;
	pid_t wait_result;
	int stat_loc;

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("### Child ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);
		sleep(1);
	}
	else
	{
		wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
		printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);
		printf("Wait result: %d\n", wait_result);
	}

	return (0);
}
