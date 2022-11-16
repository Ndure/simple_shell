#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
	int fd;

	fd = chmod("new dir", 0755);
	if (fd == -1)
	{
		perror("");
		exit(98);
	}
	printf("Permissions updated succesfully");

	return (0);
}
