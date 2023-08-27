#!/bin/bash

if [ $# -lt 1 ] 
then 
	echo "errore, nessun parametro passato"
	exit -1
fi

if [ ! -d $1 ] 
then
	mkdir $1
else
	for var in $*
	do
		if [ -f $var -a "$var"!="$1" ] 
		then 
			echo "vuoi inserire il file $var nel direttorio? (si/no)"
			read scelta
			if [ "$scelta" = "si" ] 
			then 
				cp $var $1
			fi
		fi
	done
fi
exit 0
