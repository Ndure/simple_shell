#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[], char *envp[])
{
	char *cmd1 = argv[1];

	(void)envp;
	if (argc == 1)
	{
		dprintf(2, "Usage: %s <command> <optional args>", argv[0]);
		exit(1);
	}
	
	execve(cmd1, argv, NULL);

	return (0);
}
