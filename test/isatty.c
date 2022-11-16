#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int n;

	n = isatty(4);
	printf("%d\n", n);
	return (0);
}
