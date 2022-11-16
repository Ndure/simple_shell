#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, fp)) != -1)
	{
		printf("i = %d and len = %lu\n", i++, len);
		printf("Retrieved line of length %ld:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	free(line);
	fclose(fp);

	exit(EXIT_SUCCESS);
}
