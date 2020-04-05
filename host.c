#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "coniox/coniox.h"
#include "host.h"

#define output(...) {mvCursor(X_START, Y_START+line); printf(__VA_ARGS__); line++;}

char *get_buf_name(char *fname);
void get_file_info(char *fname);

int line = 0;

int main(int argc, char *argv[]) {
	char cmd[256] = "";	

	if (argc < 2) {
		fprintf(stderr, "%s: %s <fname>\n", argv[0]);
		return 0;
	}

	clean();

	/* buffer creation */

	// sprintf(cmd, "%s/%s %s %d", SERV_DIR, OUTPUT_SERVICE, get_buf_name(argv[1]), COL_MAX);
	sprintf(cmd, "%s/%s %s %d", SERV_DIR, OUTPUT_SERVICE, argv[1], COL_MAX);
	system(cmd);

	get_file_info(argv[1]);
	return 0;
}

char *get_buf_name(char *fname) {
	return strcat(fname, "_buf");
}

void get_file_info(char *fname) {
	struct stat buf;

	stat(fname, &buf);

	output("NAME: %s", fname);
	output("SIZE: %d", buf.st_size);
	output("UOID: %d", buf.st_uid);
}
