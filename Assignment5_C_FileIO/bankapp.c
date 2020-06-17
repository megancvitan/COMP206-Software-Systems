/* Name: Megan Cvitan
 Department of Physics
 *************************************
 Changes Made
 Date: 11/03/2020 Initial Creation
 Date: 13/03/2020 Fixing the balance method and commenting 
 *************************************
 Statement of Purpose
 This program will simulate a banking app. The user will be able to add an account number, make deposits and make withdrawals. 
*/

// importing libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// checking to see if an account exists
int exists(char *file, int account_number){
	FILE *FilePointer;
	// open the file and read from it
	FilePointer = fopen(file, "r");
	// look through each row in the file to see if the account names and account numbers match
	// returns 1 if it does, returns 0 if it doesnt find the account
	
	// prepares the empty array of chars
	char characters[38];
	while (fgets(characters, sizeof(characters), FilePointer)){
		// check first two characters from file
		if (characters[0] == 'A'){
			// if an action occurred (checking name), access the values
		 	char *splitter = strtok(characters, ",");
			splitter = strtok(NULL,",");
			// do it again to get the account number out so we can use it
			char *acc_num =  splitter;
			int n = atoi(acc_num);
			// if they are equal, we found the account
			if (n == account_number){
				return 1;
			}
		}
	}
	fclose(FilePointer);
       	return 0;
}

float balance(char *filename, int acc_num)
{
	FILE *FilePointer;
	FilePointer = fopen(filename, "r");

	// looking for all transactions from a certain bank account
	float money = 0;
	char characters[100];
	float transaction = 0;
	int acc = 0;
	while (fgets(characters, sizeof(characters), FilePointer)){
		// if we see a transaction
		if (characters[0] == 'T'){
			char *split = strtok(characters,",");
			char *accie;
			// collect all of the account numbers
			for (int i = 0; i<2; i++){
				accie = split;
				split = strtok(NULL,",");
				
			}
			split = strtok(NULL, ",");

			// if it is for the same account, add it to the balance
			transaction = atof(split);
			// and turn it into a string
			acc = atoi(accie);
			if (acc_num == acc){
				money = money + transaction;
			}
		} 
	}
	fclose(FilePointer);
       	return money;
}

// main method so it can run 
int main(int argc, char *argv[])
{
	// if the file exists, read from it
	FILE *file;
	if (!(file = fopen("bankdata.csv", "r"))){
		fprintf(stderr, "%s", "Error unable to locate the data file bankdata.csv \n");
		exit(100);
	}
	// if no arguments are given show the instructions
	if (argc == 1){
		fprintf(stderr, "%s", "Error, incorrect usage!\n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTUM DATE AMOUNT\n");
		exit(1);
	}
	// open the file before we begin
	file = fopen("bankdata.csv", "a");

	// depending on the option given, we will perform differnt actions on the account
	if (strcmp(argv[1], "-a") == 0){
	// if we want to add an account
	// make sure we only have 3 arguments first
		if (argc != 4){
			fprintf(stderr, "%s", "Error, incorrect usage!\n-a ACCTNUM NAME\n");
			exit(1);
		}
		// now scan the csv file
		if (exists("bankdata.csv", atoi(argv[2])) == 0){
			// if we cant find the account already, find the string and add it
			char line[38];
			strcpy(line,"AC,");
			strcat(line,argv[2]);
			strcat(line,",");
			strcat(line,argv[3]);
			strcat(line,"\n");
			// add it to the file
			fputs(line,file);
			exit(0);
		} else {
			// if it finds it already, no need to add it again
			
			fprintf(stderr,"Error, account number %s already exists", argv[2]);
			exit(50);
		}

	} else if (strcmp(argv[1], "-w") == 0){
		// if we want to withdraw money from an account
		if (argc != 5){
			// give message
			fprintf(stderr, "%s", "Error, incorrect usage!\n-w ACCTNUM DATE AMOUNT\n");
			exit(1);
		} else if(exists("bankdata.csv", atoi(argv[2])) == 0){
			fprintf(stderr, "Error, account number %s does not exist\n", argv[2]);
			exit(50);
		}
		// find the balance for this bank account	
		float total_balance = balance("bankdata.csv", atoi(argv[2]));
		float amount = atof(argv[4]);

		// if we are trying to take out more money than we have
		if (amount > total_balance){
			// you cant do that
			fprintf(stderr, "Error, account number %s has only %.2f\n", argv[2], total_balance);
			exit(60);
		} else {
			char line2[100];
	                strcpy(line2,"TX,");
        	        strcat(line2,argv[2]);
                	strcat(line2,",");
               		strcat(line2,argv[3]);
               		strcat(line2,",-");
               		strcat(line2,argv[4]);
                	// add it to the file
                	fputs(line2,file);
                	exit(0);


		}

	} else if (strcmp(argv[1], "-d") == 0){
		// if we want to deposit money into an account
		
		// make sure there are 5 arguments or else it cant do it
		if (argc != 5){
			fprintf(stderr, "%s", "Error, incorrect usage!\n-d ACCTNUM DATE AMOUNT\n");
			exit(1);
		}

		int condition = exists("bankdata.csv", atoi(argv[2]));
		if (condition == 0){
			// the account doesnt exist, so we cant add money to it
		        fprintf(stderr,"Error, account number %s does not exist", argv[2]);
			exit(50);
		}
		char line2[100];
		strcpy(line2,"TX,");
		strcat(line2,argv[2]);
		strcat(line2,",");
		strcat(line2,argv[3]);
		strcat(line2,",");
		strcat(line2,argv[4]);
		// add it to the file
		fputs(line2,file);
		exit(0);
	}
	fclose(file);
}
