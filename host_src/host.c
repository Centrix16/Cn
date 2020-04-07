/*
 * host -- combines services together
 * v0.6
 * 06.04.2020
 * Nifra -- ASZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <sys/stat.h>

#include "../coniox/coniox.h"
#include "host.h"

int main(int argc, char *argv[]) {
	void (*flag_funcs[])() = {switch_m, switch_h, switch_v, switch_d, switch_H, switch_a};
	char *fname = NULL; 

	if (argc < 2) {
		fprintf(stderr, "%s: %s <fname> <optional-flags>\n", argv[0]);
		return 0;
	}

	fname = argv[1];

	if (argc == 3) {
		proc("mhvdHa", flag_funcs, 6, argv[2]);
	}

	if (get_m())
		setWindowSize(LENGHT, HEIGHT);
	if (get_use_help_file())
		fname = "doc/help";
	if (!get_direct_use())
		; /* buffer creation */
	if (get_locale())
		setlocale(LC_ALL, " ");
	
	clean();

	// update(get_buf_name(argv[1]));
	update(fname);

	get_file_info(fname);
	navigation(fname);
	clean();

	return 0;
}
