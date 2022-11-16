#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *argv[] = {"ls", "-a", "-h", "-l", NULL};
	execvp(argv[0], argv);

	return (0);
}
