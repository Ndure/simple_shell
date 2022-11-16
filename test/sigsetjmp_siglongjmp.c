#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>

static sigjmp_buf env;
static volatile sig_atomic_t jump_active = 0;

void sigint_handler(int signo)
{
	(void)signo;

	if (jump_active == 0)
		return;
	siglongjmp(env, 42);
}

int main(void)
{
	int n;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		n = sigsetjmp(env, 1);
		if (n == 42)
		{
			printf("restart\n");
		}
		jump_active = 1;
		printf("next iteration...\n");
		sleep(2);
	}
	return (0);
}
