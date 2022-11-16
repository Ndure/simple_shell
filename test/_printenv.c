#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
	int i = 0;

	(void)argc;
	(void)argv;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	printf("%p\n", *environ);
	printf("%p\n", *envp);

	return (0);
}
