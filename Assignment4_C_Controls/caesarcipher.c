/*
Program to implement a simple calculator
**********************************************************
* Author        Dept.           Date            Note
**********************************************************
* Megan Cvitan  Physics         Feb 16 2020     Initial version
* Megan Cvitan  Physics		Feb 16 2020     Final edits
*/

// importing packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	// if there is no argument given
	if (argc != 2){
		printf("Error: usage is caesarchipher <offset>\n");
		exit(1);//code
	}
	
	char code[250];
	int offset = atoi(argv[1]);
	//if there are arguments
	bool detecc = true;

	while(detecc){
		// you must take in one char, and it cant be an enter
		// if there is an endline then also quit it
		if ((strlen(code) == 1 && (code[0]=='\n' || code[0]=='\r')) || fgets(code,sizeof(code),stdin)==NULL){
			detecc = false;
			exit(0); //different exit code
		}
		// if the offset is greater than the amount of letters
		// corrections for over or under shooting
		if (offset < 0){
			offset = -(abs(offset)%26);
		} else {
			offset = offset%26;
		}
	
		int i;	
       		int differ;
		int alph;

		for (i=0; i<strlen(code)-1; ++i){
			// ignore capital leters, punctuation, spaces
			if (code[i] < 'a' || code[i] > 'z'){
				continue;
			}
		
			//shift the chars
			alph = code[i]+offset;
		       // depending on if you overshoot or undershoot the alphabet range	
			if (alph < 'a'){
				differ = 'a' - alph;
				// typecast it
				// add one to avoid double counting a char
				code[i] = (char) ('z' - differ + 1);
			} else if (alph > 'z'){
				differ = alph - 'z';
				code[i] = (char) ('a' + differ - 1);
			} else {
				code[i] = (char)alph;
			}
		}
		printf("%s",code);
	}


}





