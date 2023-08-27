#!/bin/bash

if [ $# -lt 1 ] 
then 
	echo "manca il nome del file"
	exit -1
fi
newfilename=$(basename $1 ".txt") #crea un nuovo file prendendo i dati da input
newfilename=$newfilename".xyx"
cp $1 $newfilename		#copio il contenuto dal primo argomento al file appena creato
rm -f tmp.txt
let righeTot=$(cat $1 | wc -l)	# col comando wc -l leggo il numero di righe
while read riga
do
	parole=$(echo $riga | wc -w) #per ogni riga conto il numero di parole
	echo "$parole $righeTot $riga" >> tmp.txt	#e le metto nel file in questo ordine
done < $1 
cat tmp.txt | sort -k 1 -n > $1 # ordino il file per primo valore e specifico che sono numeri con -n
exit 0
