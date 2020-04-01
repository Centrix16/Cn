 /*
  * Remove a file
  * v0.1
  * 01.04.2004
  * Nifra -- %TAS%
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s: 1 argument required\n", argv[0]);
		return 1;
	}
	if (remove(argv[1]) == -1) {
		fprintf(stderr, "Can not delete %s\n", argv[1]);
	}
	perror("remove");
	return 0;
}