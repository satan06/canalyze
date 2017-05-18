#ifndef PROCESS_H
#define PROCESS_H

typedef struct
{
	char **f_data;
	int *c_dat;
	size_t f_ind;
	size_t c_ind;	
} ResltData;

char *get_by_prttpe(char *in_file_name);

#endif//PROCESS_H