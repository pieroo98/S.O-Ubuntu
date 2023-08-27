#!/bin/bash

if [ $# -lt 1 ] 
then 
	echo "errore passaggio parametri"
	exit -1
else
	let n=1
	let totPar=0
	while read stringa
	do
		let c=1
		echo "riga $n letta: "
		echo "$stringa"
		for var in $stringa 
		do
			echo "stringa $c letta = $var"
			let c=c+1
			let totPar=totPar+1
		done
		let n=n+1
	done < $1
	let n=n-1
	echo "il numero di righe del file $1 sono $n"
	echo "mentre il numero di parole totali sono $totPar"
fi
exit 0
