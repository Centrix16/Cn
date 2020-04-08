/*
 * Creates a file-related buffer
 * v0.2
 * 08.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp = NULL, *buf = NULL;
	char *bufname = NULL;
	int ch = 0;

	if (argc != 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror(argv[0]);	
		return 0;
	}
	
	strcat(argv[1], "_buf");
	bufname = argv[1];

	if ((buf = fopen(bufname, "w")) == NULL) {
		perror(argv[0]);	
		return 1;
	}

	while ((ch = fgetc(fp)) != EOF) {
		fputc(ch, buf);
	}

	fclose(fp);
	fclose(buf);
	return 0;
}
