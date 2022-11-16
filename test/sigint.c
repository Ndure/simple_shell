#include <stdio.h>
#include <signal.h>

void sigint_handler(int signo)
{
	printf("\nCaught SIGINT\n");
	printf("Signal No: %d\n", signo);
}

int main(void)
{
	signal(SIGINT, sigint_handler);
	while (1);
}
