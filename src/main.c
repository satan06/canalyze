#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"
#include <stdio.h>
#include <process.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	if(scmp(argv[1], "lab.c") == 0) {
		if(argv[1] != NULL) {
			printf("Detected functions / call times: \n");
			printf("\n");
			printf("Declared via"GRN" prototype"RESET":\n");
			get_by_prttp(argv[1]);
			printf("\n");
			printf(GRN"Described"RESET" below:\n");
			get_by_descript(argv[1]);
			get_main_spec(argv[1]);			
		} else {
			printf(RED"Cannot get access\n"RESET);
			printf(YEL"FILE "RESET"could be "RED"damaged!\n"RESET);
		}
	} else {
		printf("Usage:\n");
		printf("canalize <in-file-name>\n");
	}

	return 0;
}