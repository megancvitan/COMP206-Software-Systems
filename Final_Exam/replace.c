// libraries
// can only use functions covered in class
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// replace.c will detect that the word read from the file matches word1
// if it does not match word1, it returns word2, otherwise it returns word
// assume case sensitive


// method to compare the words
// returning a pointer, pointing to the word that will be returned
char* compare(char* word, char* word1, char* word2){
	
	// strcmp returns the difference of the ascii values of the strings
	// will compare two strings character by character
	// if theyre the same, the integer returned will be 0
	int c = strcmp(word, word1);
	if (c == 0){
		// same, so return word2
		return word2;
	} else {
		// not the same, so return word
		return word;
	}
}

