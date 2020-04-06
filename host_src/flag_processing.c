#include <stdio.h>

int find(char *arr, int len, int c) {
	for (int i = 0; i < len; i++)
		if (arr[i] == c) return i;
	return -1;
}

int proc(char *flags, void (*funcs[])(), int len, char *flag) {
	int i = 1, indx = -1;

	if (*flag != '-') return 0;
	while (flag[i]) {
		indx = find(flags, len, flag[i]); 

		if (indx >= 0)
			(*funcs[indx])();
		else
			printf("no such flag %c", flag[i]);	

		i++;
	}
}
