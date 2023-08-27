#!/bin/bash

if [ $# -lt 1 ] 
then
	echo "file non passato come primo parametro"
	exit -1
else
	for str in $(cat $1)
	do
		let n=0
		echo -n "valore $str : "
		while [ $n -lt $str ] 
		do
			echo -n "*"
			let n=n+1
		done
		echo
	done
fi
exit 0
