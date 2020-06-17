// *****************************************************
// Name: Megan Cvitan
// Department: Physics
// *****************************************************
// Date: 09/04/2020
// Changes made: Initial startup
// Date: 11/04/2020
// Changes made: Fixing issue with 0 exponent
// *****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// takes a string, and two integer pointers
void parse( char string[], int* one, int* two ){
	// separatei the string we give it
	char* num = strtok(string, " ");
	// turn it into an int
	int n = atoi(num);
	*one = n;

	// do it again to get the second number
	num = strtok(NULL, " ");
	int m = atoi(num);
	*two = m;
}

// takes in two numbers, and returns the value of a^b
// cannot use math.h
// also considers what happens if we have a 0 for the power
int powi( int a, int b ){
	// if we have a base to the 0th power, return 1 always
	if (b==0){
		return 1;
	} else if (b < 0){
		// also considering negative exponents
		// supposed to return only whole numbers, so make it 0
		return 0;
	}
	int answer = a;
	// computing the answer
	for (int i=0; i<b-1; i++){
		// iterate for the amount of powers
		answer = answer*a;
	}
	return answer;
}
