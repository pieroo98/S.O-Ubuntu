#!/bin/bash

if [ $# -lt 1 ] 
then 
	echo "manca il nome del file"
	exit -1
else
	file="tmp"
	while read var1 var2
	do
		echo $var2 $var1
	done <$1 > $file
	mv $file $1
fi
exit 0
