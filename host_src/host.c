/*
 * host -- combines services together
 * v0.5
 * 06.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../coniox/coniox.h"
#include "host.h"

int main(int argc, char *argv[]) {
	void (*flag_funcs[])() = {switch_m, switch_h, switch_v};	

	if (argc < 2) {
		fprintf(stderr, "%s: %s <fname> <optional-flags>\n", argv[0]);
		return 0;
	}
	if (argc == 3) {
		proc("mhv", flag_funcs, 3, argv[2]);
	}

	if (get_m())
		setWindowSize(LENGHT, HEIGHT);

	clean();

	/* buffer creation */

	// update(get_buf_name(argv[1]));
	update(argv[1]);

	get_file_info(argv[1]);
	navigation(argv[1]);
	clean();

	return 0;
}
