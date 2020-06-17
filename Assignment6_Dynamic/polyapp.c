// *****************************************************
// Name: Megan Cvitan
// Department: Physics
// *****************************************************
// Date: 09/04/2020
// Changes made: Initial startup
// Date: 11/04/2020 
// Changes made: Fixing condition if addPolyTerm does not work
// *****************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "poly.h"
#include "utils.h"

int main( int argc, char* argv[] ){
	if ( argc != 2 ){
		// if we arent giving it only one argument, stop the process
		printf( "\nPlease give only 1 argument.\n" );
		exit(2);
	}
	// access the first argument, which will be the file name
	char* filename = argv[1];
	// make the file pointer
	FILE* file;
	if (!(file = fopen(filename, "r"))){
		// if the file we get is not found, print message and exit
		printf("Error, could not locate the file %s in this directory\n", filename);
		exit(3);
	}

	// access the lines found in the file we pass in
	char s[100];
	// open the file we give it
	fopen(filename, "r");
	char *l = fgets(s, sizeof(s), file);
	int coeff, expo;
	int cond;
	while(l){
		// collect all of the lines from the file in strings
		parse(l, &coeff, &expo);
	        cond = addPolyTerm(coeff, expo);
		
		// if it didnt work, the cond is -1
		if (cond == -1){
			// give the message
			printf("Could not add term.");
			exit(1);
		}

		// and then reads the next line
		l = fgets(s, sizeof(s), file);
	}
	// show the whole polynomial and the values for the set {-2,-1,0,1,2}
	displayPolynomial();
}
