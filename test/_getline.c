#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *lineptr;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&lineptr, &len, stdin);
	printf("%lu allocated\n%ld bytes read.\n%s", len, nread, lineptr);

	free(lineptr);

	return (0);
}
