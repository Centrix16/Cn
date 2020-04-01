/*
 * Adds a string to the file
 * v0.1
 * 01.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *src = fopen(argv[1], "r"), *dst = NULL;
	char out_fname[256] = "";
	int i = 0, c = 0, end = atoi(argv[2]);

	sprintf(out_fname, "%s_out", argv[1]);

	dst = fopen(out_fname, "w");
	if (!dst || !src) {
		perror("fopen");
		return 0;
	}

	c = fgetc(src);
	while (!feof(src) && i++ < end) {
		fputc(c, dst);
		c = fgetc(src);
	}
	fprintf(dst, "%s", argv[3]);

	c = fgetc(src);
	while (!feof(src)) {
		fputc(c, dst);
		c = fgetc(src);
	}

	fclose(src);
	fclose(dst);

	remove(argv[1]);
	rename(out_fname, argv[1]);
	return 0;
}
