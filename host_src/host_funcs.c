#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#include "../coniox/coniox.h"
#include "host.h"

#define output(...) {mvCursor(X_START, Y_START+line); printf(__VA_ARGS__); line++;}

int x = 1, y = 1;
int line = 0;

int m = 1, direct_use = 0, use_help_file = 0, locale = 1; // flags

char input_buf[1024];

void update(char *fname) {
	char cmd[256] = "";	

	sprintf(cmd, "%s%c%s %s %d", SERV_DIR, DIR_SEP, OUTPUT_SERVICE, fname, COL_MAX);
	system(cmd);
}

void add_buf(char *fname) {
	char cmd[256] = "";
	
	sprintf(cmd, "%s%c%s %s", SERV_DIR, DIR_SEP, BUF_SERVICE, fname);
	system(cmd);
}

char *get_buf_name(char *fname) {
	return strcat(fname, "_buf");
}

char *get_origin_name(char *bufname) {
	static char origin[256] = "";

	strcpy(origin, bufname);
	origin[strlen(bufname)-4] = '\0';

	return origin;
}

void get_file_info(char *fname) {
	struct stat buf;
	char *fname_ptr = fname;

	stat(fname, &buf);

	if (!direct_use)
		output("NAME: %s", get_origin_name(fname));	
	if (direct_use)
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

					if (isupper(c) && m)
						setColor(BLACK, RED, BRIGHT);
					else if (m)
						setColor(BLACK, WHITE, BRIGHT);
					putchar(c);
				}
			break;
		}

		c = readKb();
	}

	setColor(BLACK, WHITE, NORMAL);

	pos = frac_to_c(fname, y, x-1);

	sprintf(cmd, "%s%c%s %s %d \"%s\"", SERV_DIR, DIR_SEP, ADD_SERVICE, fname, pos, input_buf);
	system(cmd);

	update(fname);
}

void switch_m() {
	m = !m;
}

void switch_h() {
	printf("Cn -- text editor by %s v%s %s\n\n", AUTHORS, VERSION, DATE);	
	printf("-- flags\n\
	m - minimal use of terminal capabilities, turns off the backlight, and resizing\n\
	v - displays the version of the program\n\
	h - gives a short help\n\
	d - do not use file buffer, i.e. work directly with the file\n\
	H - opening documentation (doc/help) in the editor\n\
	a - turns off localization\n"); 
	exit(0);
}

void switch_v() {
	printf("v%s %s\n", VERSION, DATE);
	exit(0);
}

void switch_d() {
	direct_use = !direct_use;
}

void switch_H() {
	use_help_file = !use_help_file;
}

void switch_a() {
	locale = !locale;	
}

int get_m() {
	return m;
}

int get_direct_use() {
	return direct_use;
}

int get_use_help_file() {
	return use_help_file;
}

int get_locale() {
	return locale;
}
