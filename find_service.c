/*
 * Looks for a line in the argv[1] file and writes the result to the 'returned' file
 * v0.1
 * 03.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "%s: 1 argument required\n", argv[0]);
		return 1;
	}
	FILE *fp, *out;
	fp = fopen(argv[1], "r");
	out = fopen("returned", "w");
	int len = strlen(argv[2]);
	char ch;
	int result = 0, count = 0, br = 0;
	while ((ch = getc(fp)) != EOF) {
		while (count != len) {
			if (ch == argv[2][count])
				count++;
			else
				count = 0;
			result++;
			if (count == len) {
				fprintf(out, "%d", result - len);
				br = 1;
				break;
			}
			if ((ch = getc(fp)) == EOF) {
				br = 1;
				break;
			}
		}
		if (br == 1)
			break;
	}
	if (ch == EOF) {
		result = -1;
		fprintf(out, "%d\n", result);
	}
	fclose(out);
	fclose(fp);
	return 0;
}