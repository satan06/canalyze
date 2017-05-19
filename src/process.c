#define DELIM " ()*{;"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"
#include <stdio.h>
#include <strings.h>

int return_datype_valid(const char *str)
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

int get_by_descript(char *in_file_name)
{
	FILE *input_file = fopen(in_file_name, "r");
	int i = 0, buffer = 100;
	char str[buffer], *a[buffer];

    if (input_file != NULL) {
    	while (!feof(input_file)) {
      		fgets(str, sizeof(str), input_file);

      		if(schr(str, '(') && schr(str, ')') && schr(str, '{')) {
      		 	a[i++] = sstok(str, DELIM);

        		while(a[i - 1] != NULL) {
              a[i++] = sstok(NULL, DELIM);
            }
            if((return_datype_valid(a[0]) == 0) && (return_datype_valid(a[2]) == 0)) {
              printf(GRN "-> " RESET);
              printf("%s\n", a[1]);
            }
          }
      }
   		if (fclose(input_file) == EOF) { 
   			return -1;
   		}
    }
	return -1;
} 

int get_main_spec(char *in_file_name)
{
  FILE *input_file = fopen(in_file_name, "r");
  int i = 0, buffer = 100;
  char str[buffer], *a[buffer];

    if (input_file != NULL) {
      while (!feof(input_file)) {
          fgets(str, sizeof(str), input_file);

          if(schr(str, '(') && schr(str, ')') && schr(str, '{')) {
            a[i++] = sstok(str, DELIM);

            while(a[i - 1] != NULL) {
              a[i++] = sstok(NULL, DELIM);
            }
            if((return_datype_valid(a[0]) == 0) && (scmp(a[1], "main") == 0) && 
              (return_datype_valid(a[2]) == -1)) {
              printf(GRN "-> " RESET);
              printf("%s\n", a[1]);

              return 0;
            }
          }
      }
      if (fclose(input_file) == EOF) { 
        return -1;
      }
    }
  return -1;
}

int get_by_prttp(char *in_file_name)
{
  FILE *input_file = fopen(in_file_name, "r");
  int i = 0, buffer = 100;
  char str[buffer], *a[buffer];

    if (input_file != NULL) {
      while (!feof(input_file)) {
          fgets(str, sizeof(str), input_file);

          if(schr(str, '(') && schr(str, ')') && schr(str, ';')) {
            a[i++] = sstok(str, DELIM);

            while(a[i - 1] != NULL) {
              a[i++] = sstok(NULL, DELIM);
            }
            if((return_datype_valid(a[0]) == 0) && (return_datype_valid(a[2]) == 0)) {
              printf(GRN "-> " RESET);
              printf("%s\n", a[1]);
            }
          }
      }

      if (fclose(input_file) == EOF) { 
        return -1;
      }
    }
  return -1;
} 

