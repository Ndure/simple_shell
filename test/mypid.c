#include<stdio.h>
#include<unistd.h>

int main(void)
{
	pid_t n, m;

	n = getpid();
	m = getppid();
	printf("pid: %u\nppid = %u\n", n, m);
	return (0);
}
