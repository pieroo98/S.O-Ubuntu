#!/bin/bash

if [ $# -lt 1 ] 
then
	echo "nome file non passato come parametro"
	exit 0 
else
	flag=1
	rig=1
	for val in $(cat $1)
	do
		echo "valore letto $val in posizione $flag"
		if [ $flag -eq 1 ] 
		then 
			let f=3*val*val
		elif [ $flag -eq 2 ] 
		then
			let f=f+4*val
		elif [ $flag -eq 3 ] 
		then
			let f=f+5*val
			flag=0
			echo "valore funzione $f"
		fi
		let flag=flag+1
	done
fi
exit 1
