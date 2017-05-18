#define DELIM " ()*{"
#include <stdio.h>
#include <strings.h>

char **get_by_prttpe(char *in_file_name)
{
	FILE *input_file = fopen(in_file_name, "r");
	int i = 0, buffer = 50;
	char str[buffer], *estr, *a[buffer]; 

    if (input_file != NULL) {
    	printf("Detected functions: \n");
    	while (1) {
      		estr = fgets(str, sizeof(str), input_file);
      		if (estr == NULL) {
         		if (feof(input_file) != 0) {  
            		break;
         		} else {
            		break;
            		return NULL;
         		}	
      		}
      		if(schr(str, '(') && schr(str, ')') && schr(str, '{')) {
      		 	a[i++] = sstok(str, DELIM);

        		while(a[i - 1] != NULL) {
            		a[i++] = sstok(NULL, DELIM);
        		}
        		printf("%s\n", a[1]);
      		}
   		}
   		if (fclose(input_file) == EOF) { 
   			return NULL;
   		}
    }
	return NULL;
} 


