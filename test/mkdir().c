#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(void)
{
	int fd;

	fd = mkdir("new dir", 0700);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	printf("Directory created successfully.");

	return (0);
}
