/*
 * Insert text into a file
 * v0.1
 * 06.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	int pos = 0;

	if (argc != 4) {
		fprintf(stderr, "%s: %s <fname> <pos> <str>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r+")) == NULL) {
		fprintf(stderr, "Can not open the `%s` file\n", argv[1]);
	}

	pos = atoi(argv[2]);

	fseek(fp, pos, SEEK_SET);
	fprintf(fp, "%s", argv[3]);
	fclose(fp);

	return 0;
}
