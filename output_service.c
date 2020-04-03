/*
 * File output to the screen
 * v0.2
 * 02.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>

#define COL_MAX 60

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	char ch = (char)0;
	int col = 0;

	if (argc != 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can not open the `%s` file\n", argv[1]);
		return 1;
	}

	ch = getc(fp);
	while (!feof(fp)) {
		if (col++ % COL_MAX == 0 && ch != '\n')
			putchar('\n');	
		else
			putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);

	return 0;
}
