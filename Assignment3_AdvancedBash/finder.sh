#!/bin/bash

#name of the file
file="a3config"

#trying to find the config file in the directory
if [ ! -f "$file" ]
then
	message="Error cannot find $file"
	echo $message
	exit 1
fi

#imports the config file 
. $file

#looking if the user and extension are declared and set to a value
#uses the z command
if [ -z "$DIRNAME" ] || [ -z "$EXTENSION" ]
then 
	message="Error DIRNAME and EXTENSION must be set"
	echo $message
	exit 2
fi

#checking to see if the directory name is actually in the config file
#uses the d command, gives back true
#if it doesnt work, it gives an error message and you use a different exit

if [ ! -d $DIRNAME ]
then
	message="Error directory $DIRNAME does not exist"
	echo $message
	exit 3
fi

#looks to see if any files inside the dir have the extension we are looking for
#exists through exit 0 again 
#next we have to find all the files with the specified extension
#using grep, to find the files with that pattern

fil=`ls $DIRNAME | grep .*\.$EXTENSION$`
if [ -z "$fil" ]
then 
	message="Unable to locate any files with extension $EXTENSION in $DIRNAME"
	echo $message
	exit 0
fi

#for all the files that we find that match 
for files in $fil
do 	
	#always print the file name and directory
	echo "$DIRNAME/$fil"
	#show the contents of the file
        #if show is true, it is also true 
	if [ "$SHOW" == "true" ] 
	then 
		cat $fil
	fi
done
exit 0






