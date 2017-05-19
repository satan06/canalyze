[![Build Status](https://travis-ci.org/satan06/canalyze.svg?branch=master)](https://travis-ci.org/satan06/canalyze)# canalyze

WARNING! WORK STILL IN PROGRESS!

	Function "call-counter" implementation required!

Program "canalyze" analysis programs in C. The command "./canalyze" takes the input file name containing the program in the language C. The contents of the input file is subjected to a static analysis, the results of which are printed on the screen.

The following operations are envisaged:

	1. Automatic search for functions declared through a prototype or specified in the specified file.
	2. For each function found, the number of its calls in the analyzed file is counted.

The program should be launched with the following command-line arguments:

	$ canalyze <in-file-name>

Example of file content and static analysis:

	#include <stdio.h> 
	int var1, x;
	int func1(int a){ 
    	char z; 
	} 
	int func2(int a){ 
    	int x, y, z; 
    	float x; 
    	func1(x); 
	} 
	int main( ){ 
    	int a, var1; 
    	func1(a); 
    	func2(var1); 	
	}	

On display:

	Detected functions / call times: 
	
	func1:    called 2 times 
	func2:    called 1 time
	main:     called 0 times

	