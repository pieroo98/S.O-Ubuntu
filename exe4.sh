#!/bin/bash

for file in $(ls *.c)	#dalla lista generata dal comando ls prendo solo i file.c
do
	grep --quiet "POSIX" $file	#seleziono senza stampare a video tutti quelli che contengono
	if [ $? -eq 0 ] 	#al suo interno la stringa "POSIX", il risultato di questa operazione
	then			#viene salvata nella variabile $? . In caso di match $? assume valore 
		more $file	#uguale a zero e stampo il nome del file.
	fi
done
exit 0
