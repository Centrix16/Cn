 /*
  * Remove a file
  * v0.2
  * 01.04.2020
  * Nifra -- TAS
  */

#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0], argv[0]);
		return 1;
	}
	if (remove(argv[1]) == -1)
		fprintf(stderr, "Can`t delete %s\n", argv[1]);
	return 0;
}
