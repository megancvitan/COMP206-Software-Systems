// include all the libraries
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "replace.h"

// main.c controls the file processing: reading and writing to file
// it calls the functions in replace.c
// receives the return value from replace.c

// read from file
void fcheck(char *w, char *word1, char *word2, FILE *file, FILE *temp){
	// take word1, word2, and the file pointers
	// w is the word to collect from file
	char c;
	char *r;

	while ((c = fgetc(file)) != EOF){
		// consider a character c; while it is not at the end of the file
		// if c is not a letter of the alphabet, write it in the file
		// uppercase: 65 to 90, lowercase: 97 to 122
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			// collect the characters for one word at a time
			// stops when it reaches the next space or punctuation
			strncat(w, &c, 1);

		} else {
			// the char is not part of the alphabet
			// can be a space, enter
			int l = strlen(w);
			if (l >= 1){
				// if the word is collected from the file
				// use replace.h 's compare()
				r = compare(w, word1, word2);
				// add to temp file
				fputs(r, temp);
				
			}
		       	// empty the contents of w to make space for the next word
			w[0] = '\0';	

			// and add the char to the file
			fputc(c, temp);
		}	
	}
}	

// checking the arguments function
void argcheck(int argc, char *argv[]){
	if ( argc != 4){
		// otherwise give user a message
		printf("Requires 3 arguments: filename, word1, word2\n");
		exit(1);
	}
}

void edit (int argc, char *argv[]){

	// check number of arguments
	argcheck(argc, argv[]);

	// the first argument will be the file name
	char *filename = argv[1];

	// the second and third arguments are the words to compare
	char *word1 = argv[2];
	char *word2 = argv[3];

	// the word to collect from the file
	char w[1000] = "";

	// make the file pointers for the file to be read and the file to edit later
	// the temp file will later become the the original file, but with edits
	// fopen will check if the file of that name in the path exists
	FILE *file = fopen(filename, "r");
	FILE *temp = fopen("temp.txt", "w");

	// locate the file
	if (file == NULL || temp == NULL){
       		 // if it cannot be found, print message and exit
       		 printf("Could not locate the file %s\n", filename);
       		 exit(2);
	}
	
	// go over every char in the file until a space is reached
	// collect words, compare them with the inputs, and make the changes
	// with replace.h
	// then after that, add the word to the temp file, or if a space or enter or tab is encountered, just add that to the temp file
	// using fcheck() above
	
	fcheck(w, word1, word2, file, temp);

	// close the files that were open
	fclose(file);
	fclose(temp);

	// get rid of the old file
	// left with one file, with the changes made 
	remove(filename);

	// rename file as the one before
	rename("temp.txt", filename);

}


