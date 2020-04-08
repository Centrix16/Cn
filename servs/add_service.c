/*
 * Adds a string to the file
 * v0.2
 * 01.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *src = NULL, *dst = NULL;
	char out_fname[256] = "";
	int i = 0, c = 0, end = 0;

	if (argc != 4) {
		fprintf(stderr, "%s: %s <fname> <pos> <str>\n", argv[0], argv[0]);
		return 0;
	}

	sprintf(out_fname, "%s_out", argv[1]);

	src = fopen(argv[1], "r");
	dst = fopen(out_fname, "w");
	if (!dst || !src) {
		perror(argv[0]);
		return 0;
	}

	end = atoi(argv[2]);
	c = fgetc(src);
	while (!feof(src) && i++ < end) {
		fputc(c, dst);
		c = fgetc(src);
	}

	fprintf(dst, "%s", argv[3]);

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
