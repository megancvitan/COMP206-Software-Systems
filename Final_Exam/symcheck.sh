#!/bin/bash
# will accept a text file as its argument

# check if the proper amount of arguments is passed through
if [ $# -ne 1 ]
then
	# if there is not one argument
	# tell user that you need to input a single text file
	echo "One text file is required as argument"
	# exit code
	exit 3
fi

# the first argument is called filename
filename=$1

# assume in current directory
# the filename argument given must also contain the extension of the file
# and not just the name, otherwise it will not recognize it

# check to find file in this directory
if [ ! -f "$filename" ]
then
	# echo an error message
	echo "Cannot find file named $filename in current directory"
	# exit code
	exit 4
fi

# if the filename was located in the current directory, continue
# check if the words in the text file passed in are symmetric or not
# print out the word and if it is symmetric or not
# assume that symword.c is in the same directory

# compile symword.c in case it isnt done already
`gcc -o out symword.c`

# run the while loop on the filename to go over all of the lines
# one at a time; l is the line and it is updated on its own
while read l
do
	# also assume that everything is lowercase
	# run symword with the given word as argument, from file
	`./out $l`

	# save the exit code of that command every time
	code=`echo $?`

	# otherwise it will only do the last line
	# if the exit code from that command is 1
	if [ $code -eq 1 ]
	then
		# the word is not symmetric
		echo "$l is not symmetric"
	# if the exit code was 0
	elif [ $code -eq 0 ]
	then
		# then the word is symmetric
		echo "$l is symmetric"
	fi
done < $filename

