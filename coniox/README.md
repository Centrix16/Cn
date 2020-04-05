# coniox (CONsole Input / Output eXtensions)
## An overview of the available functions  

- setColor()  
	1. Prototype: `void setColor(int bg, int text, int bright);`  
	2. Destination: Change the color of the displayed text and its background  
	
	3. Arguments:  
    + bg - background color  
    + text - foreground color  
    + bright - the brightness of the text  
		
	4. The values taken by the arguments bg and text:  
     BLACK, BLUE, GREEN, AZURE, RED, PINK, YELLOW, WHITE  
    5. The value taken by the argument bright:  
     NORMAL, BRIGHT
    6. Code example:
    ```c
    ...
    setColor(BLACK, GREEN, BRIGHT);
    ...
    ```
    > This call to the setColor function changes the color of the output text to bright green with a black background.

- mvCursor()  
	1. Prototype: `void mvCursor(unsigned int x, unsigned int y);`  
	2. Destination: Changing the current cursor position in the console  
	
	3. Arguments:  
    + x - line  
    + y - column  
		
  4. The values taken by the arguments x and y:  
      MAX = ~2^32 MIN = 0 
  5. Code example:
  ```c
  ...
  mvCursor(10, 5);
  ...
  ```
  > This call to mvCursor will move the cursor to row 10 of column 5.

- cursorLeft(), currentRight(), cursorUp(), cursorDown()  
    1. Prototype: `void cursor(Up, Down, Left, Right)(unsigned int x, unsigned int y);`  
    2. Destination: Change cursor position in Up, Down, Left, Right, one character relative to x, y arguments.  
	
    3. Arguments:  
    + x - The line relative to which the shift is made  
    + y - Column relative to which the shift is made  
		
	4. The values taken by the arguments x and y:  
      MAX = ~2^32 MIN = 0
    5. Code example:
    ```c
    ...
    cursorUp(currX, currY);
    ...
    ```
    > This call to the cursorUp function will move the cursor up (that is, one character up) relative to currX and currY.
 
- clean()  
    1. Prototype: `void clean();`  
    2. Destination: Clears the console window.  
	
    3. Code example:
    ```c
    ...
    clean();
    ...
    ```
    > This call to the clean() function clears the console window.

- readKb()  
    1. Prototype: `unsigned int readKb();`  
    2. Destination: Reads the character from the keyboard, without echo output..  
	
    3. Code example:
    ```c
    ...
    symbol = readKb();
    ...
    ```
    > This function call readKb() to save into the variable symbol of the first typed symbol.

## Notes
### Symbols
**All characters mentioned in this document are *ASCII* characters.**
### Build
To build the library, you must have make, ar, and the gcc 32-bit or 64-bit compiler.  
However, coniox can also be built manually using the following commands:  
> gcc -c libconiox.c  
> ar rc libconiox.a libconiox.o
### Supported OS: Windows 2000, XP, Vista, 7, 8.x, 10, and all Unix systems.
### The library was created by Artjom Zvyagin, for training purposes, do not take too seriously. 15.07.2019
