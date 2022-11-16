#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	size_t bufsize = 2;
	size_t characters;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("Type something: ");
	characters = getline(&buffer, &bufsize, stdin);
	printf("%zu characters were read.\n", characters);
	printf("You typed: %s\n", buffer);

	return (0);
}
