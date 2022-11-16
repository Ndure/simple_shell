#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;

	fd = link("print_args.c", "p_a");
	if (fd == -1)
	{
		perror("");
		exit(1);
	}

	printf("Successfully linked");
	return (0);
}
