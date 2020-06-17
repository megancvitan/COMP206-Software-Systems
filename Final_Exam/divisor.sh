#!/bin/bash

# creating function that finds the GCF from 2 integers
div (){

	# checking to see if the number of arguments is correct
	# must be 2 or else something is wrong
	if [ $# -ne 2 ]
	then 
		echo "Invalid number of arguments."
		exit 2
	elif [ $1 -eq 0 ] && [ $2 -eq 0 ]
	then
		# if both arguments are 0
		# continue sentence "Largest divisor of ..."
		echo "unknown"
		exit 3
	fi

	# the largest divisor
	N=0

	# two inputs that will be used
	# also take the absolute value of the inputs by using sqrt
	# bash doesnt know what abs() (absolute value) is
	# bc looks for expressions to evaluate
	X=`echo "sqrt($1*$1)" | bc`
	Y=`echo "sqrt($2*$2)" | bc`

	# if one of the arguments is 0, return the other one
	if [ $X -eq 0 ]
	then
		echo $Y
		# exit code, otherwise it keeps going
		exit 5
	elif [ $Y -eq 0 ]
	then
		echo $X
		exit 6
	fi

	# checking to see which argument is lesser in value
	if [ $X -le $Y ]
	then
		# if X is equal to or less than Y, make N equal to X
		N=$X
	elif [ $Y -lt $X ]
	then
		# if Y is less than X, make N equal to Y
		N=$Y
	fi

	# while X is less than N and Y is not equal to 0
	while [ `echo "$X%$N" | bc` -ne 0 ] || [ `echo "$Y%$N" | bc` -ne 0 ]
	do
		# decrement N by one each time
		N=`echo "$N-1" | bc`
	done

	# return the value of N: divisor
	echo $N
}

# the condition for the while loop to run
# if the user gives y, and nothing else
a="y"
# while the user says "y", code will continue
while [ $a = "y" ]
do 
	# ask user for the first number
	echo Enter first number:

	# get the value
	read X

	# ask user for the second number
	echo Enter second number:

	# get the value
	read Y

	# get the divisor from div()
	d=$( div $X $Y )

	# echo the largest divisor and write message
	echo -e Largest divisor of $X and $Y is $d
	echo "Do you wish to continue ?"
	read a
done

