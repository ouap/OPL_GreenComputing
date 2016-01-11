#!/bin/bash

MAXOBJ=1000
MAXCAPACITE=500
MAXPOIDSOBJ=500

for i in {1..100}
do
	nbObj=$[1 + $[$RANDOM % $MAXOBJ]]
	capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
	
	echo "$nbObj" >> data/data_$i
	echo "$capacite" >> data/data_$i
	
	for (( j=1; j<=$nbObj; j++ ))
	do
		poids=$[1 + $[$RANDOM % $MAXCAPACITE]]
		echo $poids >> data/data_$i
	done

done
