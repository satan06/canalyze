#include <stdio.h>

char *get_by_prttpe(char *in_file_name)
{
	FILE *input_file = fopen(in_file_name, "r");
	
	if (input_file != NULL) {
		fclose(input_file);
	} else 	
		return NULL;
}
