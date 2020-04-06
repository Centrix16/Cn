/*
 * 
 * v0.1
 * 06.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s: %s <bufname>\n", argv[0], argv[0]);
		return 1;
	}
	FILE *fp, *buf;
	char *bufname = argv[1];
       	strcat(bufname, "_buf");
	fp = fopen(argv[1], "r");
	buf = fopen(bufname, "w");
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		fputc(ch, buf);
	}
	fclose(fp);
	fclose(buf);
	return 0;
}
