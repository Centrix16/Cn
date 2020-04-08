/*
 * Creates a file-related buffer
 * v0.2
 * 08.04.2020
 * Nifra -- TAS
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("hello\n");
	if (argc != 2) {
		fprintf(stderr, "%s: %s <bufname>\n", argv[0], argv[0]);
		return 1;
	}
	FILE *fp, *buf;
	char *bufname;
	sprintf(bufname, "%s_buf", argv[1]);

	printf("%s\n", bufname);
	if ((fp = fopen(argv[1], "r")) != NULL) {
		printf("hi");
		return 1;
	}
	printf("hello\n");
	perror("fopen");

	if ((buf = fopen(bufname, "w")) == NULL) {
		fprintf(stderr, "s: can not open %s file", argv[0], bufname);
		return 1;
	}
	printf("hello\n");

	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		fputc(ch, buf);
	}
	printf("hello\n");

	fclose(fp);
	fclose(buf);
	return 0;
}
