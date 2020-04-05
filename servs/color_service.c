/*
 * set text color
 * v0.2
 * 02.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <string.h>

#ifdef WIN32
	int codes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 0};

	#include <windows.h>

	void set_color(int bg, int text, int bright) {
    	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		text += bright;
    	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
	}
#else
	int codes[] = {40, 44, 42, 46, 41, 45, 43, 47, 1, 0};

	void set_color(int bg, int text, int bright) {
		text -= 10;	
		printf("\x1b[%d;%d;%dm", bright, text, bg);
	}
#endif

int get_code(char*);

char *colors[] = {"bk", "bl", "gr", "az", "rd", "pk", "yl", "wh", "-br", "-nm"};	

int main(int argc, char *argv[]) {
	if (argc != 4) {
		fprintf(stderr, "%s: %s <bg> <fg> <bright>\n", argv[0], argv[0]);
	}
	set_color(get_code(argv[1]), get_code(argv[2]), get_code(argv[3]));
	return 0;
}

int get_code(char *mnemonic) {
	for (int i = 0; i < 10; i++)
		if (!strcmp(colors[i], mnemonic)) return codes[i];
	return 0;
}
