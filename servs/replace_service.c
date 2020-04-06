/*
 * Insert text into a file
 * v0.1
 * 04.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fprintf(stderr, "%s: 1 argument required\n", argv[0]);
		return 1;
	}
	FILE *fp;
	if ((fp = fopen(argv[1], "r+")) == NULL) {
		fprintf(stderr, "Can not open the `%s` file\n", argv[1]);
	}
	int pos = atoi(argv[3]);
	fseek(fp, pos, SEEK_SET);
	fprintf(fp, "%s", argv[2]);
	fclose(fp);
	return 0;
}