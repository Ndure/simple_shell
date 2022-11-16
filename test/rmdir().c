#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(void)
{
	int fd;

	fd = rmdir("new dir");
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	printf("Directory removed successfully.");

	return (0);
}
