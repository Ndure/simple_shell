#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env;

void sigint_handler(int signo)
{
	(void)signo;
	longjmp(env, 42);
}

int main(void)
{
	int n;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		n = setjmp(env);
		if (n == 42)
		{
			printf("restart\n");
		}
		printf("next iteration...\n");
		sleep(2);		
	}

	return (0);
}
