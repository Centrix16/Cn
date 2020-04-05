#ifndef __CONIOX_H_INCLUDED__
#define __CONIOX_H_INCLUDED__

/*
 $ CONsole Input / Output eXtensions `coniox.h` v0.1
 $ Header file `coniox.h` and static library `libconiox.a` are designed to simplify the use of some 
  specific features of the terminal emulators.
 $ by Centrix
 $ 15.07.2019
 */

void setColor(int bg, int text, int bright);
void mvCursor(int x, int y);
void cursorUp(int x, int y);
void cursorDown(int x, int y);
void cursorLeft(int x, int y);
void cursorRight(int x, int y);
void clean();
unsigned int readKb();

#ifdef WIN32

	/* Windows defenitions */

	#define NORMAL 0
	#define BRIGHT 8
	#define CLEAN_SCREEN "cls"

	enum conColor {
		BLACK = 0,
		BLUE,
		GREEN,
		AZURE,
		RED,
		PINK,
		YELLOW,
		WHITE
	};

#else

	/* Unix-like OS Definitions */

	#define NORMAL 0
	#define BRIGHT 1
	#define CLEAN_SCREEN "clear"

	enum conColor {
		BLACK = 40,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		PINK,
		AZURE,
		WHITE
	};

#endif /* WIN32 */

#endif /* __CONIOX_H_INCLUDED__ */
