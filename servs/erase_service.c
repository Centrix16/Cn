/*
 * Erases string from file
 * v0.2
 * 02.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int start = 0, end = 0, i = 0, c = 0;
	FILE *src = NULL, *dst = NULL;
	char out_fname[256] = "";
	
	if (argc != 4) {
		fprintf(stderr, "%s: %s <fname> <pos-start> <pos-end>\n", argv[0], argv[0]);
		return 0;
	}

	start = atoi(argv[2]);
	end = atoi(argv[3]);

	sprintf(out_fname, "%s_out", argv[1]);

	src = fopen(argv[1], "r");
	dst = fopen(out_fname, "w");
	if (!src || !dst) {
		perror("fopen");
		return 0;
	}

	c = fgetc(src);
	while (!feof(src) && i++ < start) {
		fputc(c, dst);
		c = fgetc(src);
	}

	while (!feof(src) && i++ < end)
		fgetc(src);

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
