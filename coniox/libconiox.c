#include <stdlib.h>

/*
 $ CONsole Input / Output eXtensions library `libconiox.h` v0.1
 $ Header file `coniox.h` and static library `libconiox.a` are designed to simplify the use of some 
  specific features of the terminal emulators.
 $ by Centrix
 $ 15.07.2019
 */

#ifdef WIN32

	/* Code for Windows */

	#include <windows.h>
	#include <conio.h>

	void setColor(int bg, int text, int bright) {
    	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		text += bright;
    	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
	}

	void mvCursor(int x, int y) {
		HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD crd = {y, x};
		SetConsoleCursorPosition(hOutput, crd);
	}

	void cursorUp(int x, int y) {
		mvCursor(x-1, y);
	}

	void cursorDown(int x, int y) {
		mvCursor(x+1, y);
	}

	void cursorLeft(int x, int y) {
		mvCursor(x, y-1);
	}

	void cursorRight(int x, int y) {
		mvCursor(x, y+1);
	}

	unsigned int readKb() {
		return getch();	
	}

	void clean() {
		system("cls");
	}

#else

	/* Code for *nix */

	#include <stdio.h>
	#include <termios.h>

	static struct termios old, new;

	void setColor(int bg, int text, int bright) {
		text -= 10;	
		printf("\x1b[%d;%d;%dm", bright, text, bg);
	}

	void mvCursor(int x, int y) {
		printf("\x1b[%d;%df", x, y);
	}

	void cursorUp(int x, int y) {
		printf("\x1b[1A");
	}

	void cursorDown(int x, int y) {
		printf("\x1b[1B");
	}

	void cursorLeft(int x, int y) {
		printf("\x1b[1C");
	}

	void cursorRight(int x, int y) {
		printf("\x1b[1D");
	}

	void initTermios(int echo)	{
  		tcgetattr(0, &old); 
  		new = old; 
  		new.c_lflag &= ~ICANON; 

  		if (echo) {
      		new.c_lflag |= ECHO; 
  		}
		
		else {
      		new.c_lflag &= ~ECHO; 
  		}

  		tcsetattr(0, TCSANOW, &new); 
	}

	void resetTermios(void)	{
  		tcsetattr(0, TCSANOW, &old);
	}

	char getch(int echo) {
  		unsigned int ch;

  		initTermios(echo);
 		ch = getchar();
  		resetTermios();

  		return ch;
	}	

	unsigned int readKb() {
		return getch(0);
	}

	void clean() {
		system("clean");
	}

#endif
