/*
Program to implement a simple calculator
**********************************************************
* Author	Dept.		Date		Note
**********************************************************
* Megan Cvitan	Physics		Feb 16 2020	Initial version
* Megan Cvitan	Physics		Feb 16 2020	Final edits
*/

// importing packages
#include <stdio.h>
#include <stdlib.h>

// main method
int main(int argc, char *argv[])
{
	// if the number of arguments is not 4
	if (argc != 4){
		//show this error message and exit code 1
		printf("Error: usage is simplecalc <x> <op> <y>\n");
		exit(1);
	}

	// declaring the arguments
	int x = atoi(argv[1]);
	int y = atoi(argv[3]);
	char *op = argv[2];
	int answer;

	// what to do in each operator case
	switch (*op){
		case '+':
			answer = x+y;
			printf("%d\n",answer);
			exit(0);

		case '-':
			answer = x-y;
			printf("%d\n",answer);
			exit(0);

		case '*':
			answer = x*y;
			printf("%d\n",answer);
			exit(0);
		case '/':
			answer = x/y;
			printf("%d\n",answer);
			exit(0);
		// if there is no correct operator given
		default:
			printf("%c not a valid operator",*op);
			exit(2);//with a different code
	}
}


