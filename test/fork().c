#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a program that illustrates fork and sleep function in C
 *
 * Return: returns 0
 */
int main(void)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("### Child ###\n1. Current PID: %d and Child PID: %d\n", getpid(), child_pid);
	}
	else
	{
		sleep(1);
		printf("### Parent ###\n2. Current PID: %d and Child PID: %d\n", getpid(), child_pid);
	}

	return (0);
}
