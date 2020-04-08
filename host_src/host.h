#ifndef __CN_TEXT_EDITOR_HOST_H_INCLUDED__
#define __CN_TEXT_EDITOR_HOST_H_INCLUDED__

#define VERSION "0.7"
#define DATE "08.04.2020"
#define AUTHORS "Nifra (ASZ&TAS)"

#define SERV_DIR "bin"

#define OUTPUT_SERVICE "os"
#define ADD_SERVICE "ads"
#define BUF_SERVICE "bs"

#define COL_MAX 64
#define COL_END 100
#define USER_INPUT_DEFAULT_COL_OFFSET 4 
#define USER_INPUT_DEFAULT_ROW 7

#define X_START 68
#define Y_START 3

#define ESC 27
#define NL 10
#define BS 127

#define LENGHT 100
#define HEIGHT 30

#ifdef WIN32
	#define DIR_SEP '\\'
#else
	#define DIR_SEP '/'
#endif

/* host_funcs.c */
char *get_buf_name(char*);
void get_file_info(char*);
void navigation(char*);
void input(char*);
void update(char*);
void add_buf(char *fname);
int frac_to_c(char*, int, int);

int get_m(),
	get_direct_use(),
	get_use_help_file(),
	get_locale();

/* flags function */
void switch_m(), 
	 switch_h(), 
	 switch_v(),
	 switch_d(),
	 switch_H(),
	 switch_a();

/* flags_processing.c */
int proc(char*, void (*funcs[])(), int, char*);
int find(char *arr, int len, int c);
#endif
