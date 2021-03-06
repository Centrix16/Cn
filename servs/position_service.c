/*
 * Changes the cursor position in the console
 * v0.2
 * 03.02.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
	#include <windows.h>

	void mv_cursor(int x, int y) {
		HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD crd = {y, x};
		SetConsoleCursorPosition(hOutput, crd);
	}
#else
	void mv_cursor(int x, int y) {
		printf("\x1b[%d;%df", y, x);
	}
#endif

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "%s: %s <x> <y>\n", argv[0], argv[0]);
		return 0;
	}

	mv_cursor(atoi(argv[1]), atoi(argv[2]));
	return 0;
}
