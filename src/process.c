#define DELIM " ()*{;"
#include <stdio.h>
#include <strings.h>

int return_datype_valid(char *str)
{
  if((scmp(str, "char") == 0) ||
    (scmp(str, "int") == 0) ||
    (scmp(str, "float") == 0) ||
    (scmp(str, "double") == 0) ||
    (scmp(str, "void") == 0)) {
   
    return 0;
  }
  return -1;  
}

char *get_by_descript(char *in_file_name)
{
	FILE *input_file = fopen(in_file_name, "r");
	int i = 0, buffer = 100;
	char str[buffer], *estr, *a[buffer];

    if (input_file != NULL) {
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
            if((return_datype_valid(a[0]) == 0) && (return_datype_valid(a[2]) == 0)) {
              printf("%s\n", a[1]);
            }
          }
      }

   		if (fclose(input_file) == EOF) { 
   			return NULL;
   		}
    }
	return NULL;
} 

char *get_main_spec(char *in_file_name)
{
  FILE *input_file = fopen(in_file_name, "r");
  int i = 0, buffer = 100;
  char str[buffer], *estr, *a[buffer];

    if (input_file != NULL) {
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
            if((return_datype_valid(a[0]) == 0) && (scmp(a[1], "main") == 0) && 
              (return_datype_valid(a[2]) == -1)) {
              printf("%s\n", a[1]);
            }
          }
      }

      if (fclose(input_file) == EOF) { 
        return NULL;
      }
    }
  return NULL;
}

