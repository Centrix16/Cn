/*
 * File output to the screen
 * v0.4
 * 06.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <stdlib.h>
#include "../coniox/coniox.h"

#ifdef WIN32
	#define SUB 1
#else
	#define SUB 0
#endif

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	char ch = (char)0;
	int col = 0, col_max = 0;

	if (argc != 3) {
		fprintf(stderr, "%s: %s <fname> <col-max>\n", argv[0], argv[0]);
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror(argv[0]);	
		return 1;
	}

	mvCursor(1-SUB, 1-SUB);
	setColor(BLACK, WHITE, NORMAL);

	col_max = atoi(argv[2]);
	ch = getc(fp);
	while (ch != EOF) {
		if ((col == col_max) && ch != '\n') {
			putchar('\n');
			col = 0;
		}
		else if (ch == '\n')
			puts("~");	
		else
			putchar(ch);

		ch = getc(fp);
		col++;
	}
	fclose(fp);

	return 0;
}
