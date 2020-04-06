/*
 * host -- combines services together
 * v0.4
 * 06.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#include "coniox/coniox.h"
#include "host.h"

#define output(...) {mvCursor(X_START, Y_START+line); printf(__VA_ARGS__); line++;}

char *get_buf_name(char*);
void get_file_info(char*);
void navigation(char*);
void input(char*);
void update(char*);
int frac_to_c(char*, int, int);

int x = 1, y = 1;
int line = 0;

char input_buf[1024];

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0]);
		return 0;
	}

	setWindowSize(LENGHT, HEIGHT);

	clean();

	/* buffer creation */

	// update(get_buf_name(argv[1]));
	update(argv[1]);

	get_file_info(argv[1]);
	navigation(argv[1]);
	clean();

	return 0;
}

void update(char *fname) {
	char cmd[256] = "";	

	sprintf(cmd, "%s/%s %s %d", SERV_DIR, OUTPUT_SERVICE, fname, COL_MAX);
	system(cmd);
}

char *get_buf_name(char *fname) {
	return strcat(fname, "_buf");
}

void get_file_info(char *fname) {
	struct stat buf;

	stat(fname, &buf);

	output("NAME: %s", fname);
	output("SIZE: %d", buf.st_size);
	output("UOID: %d", buf.st_uid);
	output("LMOD: %s", ctime(&buf.st_ctime));
	output("CPOS: %d-%d", x, y);

	output("USER INPUT");
	output("%s", input_buf);
}

void navigation(char *fname) {
	int c = 0;

	while (c != ESC) {
		switch (c) {
			case 'h':
			case 'a':
				if (x > 1)
					x--;	
			break;

			case 'j':
			case 's':
				y++;
			break;

			case 'k':
			case 'w':
				if (y > 1)
					y--;
			break;

			case 'l':
			case 'd':
				if (x < COL_MAX)
					x++;	
			break;

			default:
				if (c == 'i')
					input(fname);	
			break;
		}

		mvCursor(X_START, Y_START+4);
		printf("CPOS: %d-%d", x, y);

		mvCursor(x, y);
		c = readKb();
	}
}

int is_valid_c(int c) {
	if ((isprint(c) || isspace(c)) && c != '\n') return 1;

	return 0;
}

// rows and columns to columns (in file)
int frac_to_c(char *fname, int rows, int columns) {
	FILE *file = fopen(fname, "r");	
	int out = 0, c = 0;

	if (!file) {
		perror("fopen");	
		exit(0);
	}

	for (int i = 0; i < rows-1; i++) {
		c = fgetc(file);

		while (c != '\n') {
			out++;	
			c = fgetc(file);
		}
		out++;
	}

	fclose(file);
	return out+columns;
}

void input(char *fname) {
	int c = 0, i = 0, col = USER_INPUT_DEFAULT_COL_OFFSET, row = USER_INPUT_DEFAULT_ROW;
	int pos = 0;
	char cmd[256] = "";

	while (i < 1024 && c != ESC) {
		switch (c) {	
			case NL:
				row++;
				col = USER_INPUT_DEFAULT_COL_OFFSET;
				input_buf[i++] = '\n';

				mvCursor(X_START+col, Y_START+row);
			break;

			case BS:
				if (X_START+(col-1) == X_START+USER_INPUT_DEFAULT_COL_OFFSET-1) {
					row--;
					col = COL_END-X_START;
				}

				if (row > USER_INPUT_DEFAULT_ROW-1) {
					input_buf[--i] = 0;
					mvCursor(X_START+(--col), Y_START+row);
					putchar(' ');
					mvCursor(X_START+col, Y_START+row);
				}
			break;

			default:		
				if (is_valid_c(c)) {
					input_buf[i++] = c;

					if ((X_START+col) == COL_END) {
						row++;
						col = USER_INPUT_DEFAULT_COL_OFFSET;
					}

					mvCursor(X_START+col++, Y_START+row);

					if (isupper(c))
						setColor(BLACK, RED, BRIGHT);
					else
						setColor(BLACK, WHITE, BRIGHT);
					putchar(c);
				}
			break;
		}

		c = readKb();
	}

	setColor(BLACK, WHITE, NORMAL);

	pos = frac_to_c(fname, y, x-1);

	sprintf(cmd, "%s/%s %s %d \"%s\"", SERV_DIR, ADD_SERVICE, fname, pos, input_buf);
	system(cmd);

	sprintf(cmd, "%s/%s %s %d", SERV_DIR, OUTPUT_SERVICE, fname, COL_MAX);
	system(cmd);
}
