#include <stdio.h>
#include <process.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	if(scmp(argv[1], "lab.c") == 0) {
		printf("Detected functions: \n");
		printf("\n");
		printf("Declared via prototype:\n");
		get_by_prttp(argv[1]);
		printf("\n");
		printf("Described below:\n");
		get_by_descript(argv[1]);
		get_main_spec(argv[1]);
	} else {
		printf("Usage:\n");
		printf("canalize <in-file-name>\n");
	}

	return 0;
}