/*
 * File output to the screen
 * v0.1
 * 02.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s: 1 argument required\n", argv[0]);
		return 1;
	}
	FILE *fp;
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can not open the %s file\n", argv[1]);
		return 1;
	}
	char ch;
	while ((ch = getc(fp)) != EOF) {
		putchar(ch);
	}
	fclose(fp);
	return 0;
}