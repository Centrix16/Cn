 /*
  * Creature a file
  * v0.2
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
	FILE *fp;
	fp = fopen(argv[1], "a");
	fclose(fp);
	return 0;
}