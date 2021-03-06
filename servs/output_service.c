/*
 * File output to the screen
 * v0.5
 * 09.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <stdlib.h>
#include "../coniox/coniox.h"

#ifdef WIN32
	#define START 0
#else
	#define START 1
#endif

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	int ch = 0;
	int col = 0, col_max = 0;

	if (argc != 3) {
		fprintf(stderr, "%s: %s <fname> <col-max>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror(argv[0]);	
		return 1;
	}

	mvCursor(START, START);
	setColor(BLACK, WHITE, NORMAL);

	col_max = atoi(argv[2]);
	ch = getc(fp);
	while (ch != EOF) {
		if ((col == col_max) && ch != '\n') {
			printf("\n%c", ch);
			col = 0;
		}
		else if (ch == '\n') {
			puts("~");
			col = 0;
		}
		else
			putchar(ch);

		ch = getc(fp);
		col++;
	}
	fclose(fp);

	return 0;
}
