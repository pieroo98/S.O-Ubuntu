#!/bin/bash

if [ $# -lt 1 ] 
then 
	echo "errore numero parametri, sono solo $#"
	exit -1
fi

if [ ! -d $1 ] 
then 
	echo "non e' un direttorio"
	exit -2
else
	find $1 -maxdepth 1 -type d | while read -r dire
	do 
		printf "%s:\t" "$dire"
		find "$dire" -type f | wc -l
	done

fi
exit 0
