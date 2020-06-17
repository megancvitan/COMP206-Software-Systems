// checking to see if a word is symmetric or not
// arguments will consist of only lowercase letters
// terminates with exit code 0 for symmetric word
// terminates with exit code 1 for non symmetric word
// not allowed to use arrays except for the argument given

// importing things
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

        // check to see if only one word is given as input
        if (argc != 2){
		// print message and exit
                printf("You must submit only one word as input\n");
                exit(3);
        }

	// get the number of characters in the given word
	int s = strlen(argv[1]);
	
	// also if the word is one character long, its symmetric right away
	if (s == 1){
		exit(0);
	}
	
	// look at even or odd numbers of characters in the word
	// first consider the even case
	if (s%2 == 0){

		// making the indices from the left and right
		// will start at both ends of a word and move inwards
		int r = s-1;
		int l = 0;

		while (l<r){
			if (argv[1][r] == argv[1][l]){
				// update the indices to compare next time
				r = r - 1;
				l = l + 1;
			} else {
				// a pair of chars was not equal
				// it must be non symmetric
				exit(1);
			}
		}
		// it must be symmetric
		// exit with code 0 for symmetric
		exit(0);

	} else if (s%2 == 1){
	
		// consider the odd case
	 	int mid = s/2;
		// keep a counter of how pairs were compared
	 	int c = 1;
		// the amount of letters that were looked at
		int w = 1;

		// while the count is not equal to the siz
		// if the count is equal to or greater than the size
		// it means that the whole word was looked over
		while (w != s){
			// moving away from the middle letter of the word
			if (argv[1][mid+c] == argv[1][mid-c]){
				// update the number of characters considered
				// update the index to compare
				w = 2*c + 1;
				c = c + 1;
			} else {
				// if the characters arent the same
				// you know that it is not symmetric
				// because a pair of characters was not equal
				exit(1);
			}
		}
		// if it reaches here, it must be symmetric
		// exit with code 0 for symmetric
		exit(0);	
	}
}
