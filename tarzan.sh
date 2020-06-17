#!/bin/bash

########################################################
#The purpose of this script is to determine if a certain
#file exists inside a tar file.
#To do this, the grep command is used to look for the 
#specified file and the tar function is used. 
#######################################################


filename=$1
tarfilename=$2
#define the arguments

#checking if there are only 2 arguments
if  [ $# -ne 2 ]
then
	echo "Usage $0 filename tarfile "
	exit 1
fi

#checking to see if the tar file is even in the directory
if [ ! -f $tarfilename ]
then 
	echo "Error cannot find tar file $tarfilename"
	exit 1
fi

#looking through all of the directories, find a file with
#the specified file name. the grep options will interpret 
#the pattern we give it as extended regular expressions,
#not print the result, and only select the patterns
#that match the entire line.

#for the tar command, the options mean:
#f: uses archive file (the file that we give it)
#t: lists the contents of the directory
if tar -tf $tarfilename | grep -Eqx "(.*/)?$filename"
then
	echo "$filename exists in $tarfilename"
else
	echo "$filename does not exist in $tarfilename"
	exit 1
fi


