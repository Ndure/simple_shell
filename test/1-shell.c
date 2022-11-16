#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	int ch, i;
	char buf[1024];

	while (1)
	{
		i = 0;
		write(1, "$ ", 3);
		do {
			ch = getchar();
			if (ch == EOF)
			{
				write(1, "\n", 2);
				exit(0);
			}
			buf[i] = ch;
			i++;
		} while (ch != '\n');
		buf[i] = '\0';
		write(1, buf, strlen(buf));
	}

	return (0);
}
