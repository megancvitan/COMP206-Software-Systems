#!/bin/bash
###########################################
##########################################

#finding the arguments
argc=0
arga=0
while getopts ":ca" opt;
do
	case ${opt} in
		c ) argc=1;;
		a ) arga=1;;
	esac
done

#we always want the pattern to be argument 1
shift $[$OPTIND - 1]
# also if there are no arguments, then the pattern is not there
# then that means you are not looking for anything in the files

#if there is less than one argument then tell the user
if [ $# -lt 1 ]
then
	echo "Error missing the pattern argument."
	echo "Usage $0 [-c] [-a] pattern [path]"
	exit 1

#if there is only one argument, it must be the pattern 
elif [ $# -eq 1 ]
then 
	path=$PWD

#if there are two arguments  
elif [ $# -eq 2 ]
then
	if [ ! -d $2 ]
	then 
		echo "Error $2 is not a valid directory"
		exit 2
	fi
	path=$2
fi

#takes the path given by the user and looks for pattern in directory
f=`ls $path | grep $1`

#if no pattern like this exists
if [ $? -eq 1 ]
then 
	echo "Unable to locate any files that has pattern $1 in its names in $path."
	exit 3
fi

#if a is not given
if [ $arga -eq 0 ]
then
	f=`ls $path | grep $1 | head -1`
fi

#if c is not given
if [ $argc -eq 0 ]
then 
	for i in $f
	do
		echo "$path/$i"
	done
else
	for j in $f
	do
		echo "==== Contents of: $path/$f ===="
		cat $path/$j
	done
fi



