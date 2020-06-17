#!/bin/bash
#we must change the welcome settings of the terminal when it is opened
#this file will talk to .bash_profile to run the commands

logfile=".bash_profile"
path=`pwd ~/.bash_profile`
path2=`pwd`

#get hostname
host=`hostname`

#deletes the file before we begin to make sure it does not repeat info
> $path/$logfile

#redirecting the command into the bash profile 
echo -e "host=\`hostname\`" >> $path/$logfile
echo echo "Welcome to \$host!" >> $path/$logfile

#we need to find out how many instances of a user login there are
#who will show the people signed in
#grep will help filter only the user that we want
#and then wc returns the number of matching patterns from grep 

number=`who | grep $USER | wc -l`

echo echo "You have $number login sessions to this host." >> $path/$logfile
echo echo \`fortune\` >> $path/$logfile

#alias the command comp206
echo alias comp206=\'cd $path2/Projects/COMP206\' >> $path/$logfile

#do something cool
#i choose to use figlet for fancy writing
message="Bonjour/Hi"
echo echo $message \| figlet >> $path/$logfile

#and then we want to customize the ps1 string
echo export PS1=\"$USER@\$host[$(date +%H:%M:%S)]:\\w\\$ \" >> $path/$logfile

