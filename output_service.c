/*
 * File output to the screen
 * v0.2
 * 02.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	char ch = (char)0;

	if (argc != 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can not open the `%s` file\n", argv[1]);
		return 1;
	}

	while ((ch = getc(fp)) != EOF) {
		putchar(ch);
	}
	fclose(fp);

	return 0;
}
