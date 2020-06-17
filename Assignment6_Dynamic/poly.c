// *****************************************************
// Name: Megan Cvitan
// Department: Physics
// *****************************************************
// Date: 10/04/2020
// Changes made: Initial startup
// Changes made: Fixing addPolyTerm
// Date: 11/04/2020
// Changes made: writing displayPolynomial
// Date: 14/04/2020
// Changes made: Fixed the sign problem in displayPolynomial
// *****************************************************

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// making each object in the linked list
// each element is pointing to the next element
struct PolyTerm{
	int coeff;
	int expo;
	struct PolyTerm *next;
};

// global variable, used to keep track of the polynomial linked list
struct PolyTerm head;

// assimilates that term into the existing polynomial
// it will return an integer as its return value: 0 means success, and -1 means failure
int addPolyTerm ( int coeff, int expo ){
	struct PolyTerm *p = (struct PolyTerm*) malloc(sizeof(struct PolyTerm));
	// memory cant be allocated if malloc returns null, and use exit code 1
	if (p==NULL){
		return -1;
	}
	
	// pointers
	p->coeff = coeff;
	p->expo = expo;

	// starting at the head
        struct PolyTerm *current = &head;

	if ( head.coeff==0 && head.expo==0 && head.next==NULL ){
		head.coeff = coeff;
		head.expo = expo;
		return 0;
	} else if ( head.next==NULL ){
		// if there is no next element
		 if (current->expo == p->expo){
                                // to add terms with same power
                                current->coeff = current->coeff + p->coeff;
                                // and delete the thing we added after
                                free(p);
	        } else {
			// go to the next element
			head.next = p;
		}
		return 0;
	} else {
		int cond = 0;
		while (cond==0){
			// while cond is true
			if (current->expo == p->expo){
				// to add terms with same power
				current->coeff = current->coeff + p->coeff;
				// and delete the thing we added after
				free(p);
				return 0;
			} else if ( !current->next ){
				// if there is no next
				current->next = p;
				cond = 1;
			} else {
				current = current->next;
			}		
		}
		return 0;
	}
	// return -1 again if none of the conditions above were invoked
	return -1;
}

// making a function that gets the size of the linked list
int sizeOfList(){
	// get list
	struct PolyTerm *current = &head;
	int count = 1;
	// keep count of the iterations
	while(current->next){
		count = count+1;
		// go to the next node
		current = current->next;
	}
	// tell us the number of iterations, it is the size of the list
	return count;
}

// making function that returns array of exponents
// takes in the array of exponents and its size
void linkedListToExp(struct PolyTerm* ex, int s){
// we have access to the linked list through head
	 struct PolyTerm *current = &head;
         for (int i=0; i<s; i++){
	         ex[i] = *current;
		 current = current->next;
         }
}

void sortList(struct PolyTerm* l, int s){
	// sorts an array of PolyTerm in order of exponents
	// takes in a PolyTerm array, and its size
	// returns nothing but it sorts the list
	struct PolyTerm t;

	for (int i=0; i<s; i++){
		for (int j=i+1; j<s; j++){
			if (l[i].expo > l[j].expo){
				t = l[i];
				l[i] = l[j];
				l[j] = t;
			}
		}
	}
}

// returns you an integer that is obtained by evaluating the polynomial
// takes in an x value that we will substitute later
int evaluatePolynomial ( int x ){
        struct PolyTerm *current = &head;
        int answer = 0;
        while(current){
		// update the answer for each term we add
                answer = powi(x,current->expo)*current->coeff + answer;
		current = current->next;
        }
        return answer;
}

// will display the polynomial that we get
// does not take arguments or return anything, but it prints
void displayPolynomial (){
	// get the size of the list from our other method sizeOfList
	int s = sizeOfList();
	struct PolyTerm exp[s];
	linkedListToExp(exp,s);
	// sort the linked list that we are working with
	sortList(exp,s);

	char sign;
	for (int i=0; i<s; i++){
		// checks the sign first
		if (exp[i].coeff < 0){
			// if its negative, sign is -
			sign = '-';
		} else {
			// if its positive then +
			sign = '+';
		}
		if (i == 0){
			printf("%dx%d", exp[i].coeff, exp[i].expo);
			if (s == 1){
				printf("\n");
			}
		} else if (i == s-1){
			// consider the sign now
			printf("%c%dx%d\n", sign, abs(exp[i].coeff), exp[i].expo);
		} else {
			printf("%c%dx%d", sign, abs( exp[i].coeff), exp[i].expo);
		}
	}

	// the solutions that we want to see
	int w[5] = {-2, -1, 0, 1, 2};
	int y;
	for (int i=0; i<5; i++){
		// compute the answer
		y = evaluatePolynomial(w[i]);
		printf("for x=%d, y=%d\n", w[i], y);
	}
}


