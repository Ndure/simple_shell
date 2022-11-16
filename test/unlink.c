#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;

	fd = unlink("p_a");
	if (fd == -1)
	{
		perror("");
		exit(1);
	}

	printf("Successfully unlinked");
	return (0);
}
