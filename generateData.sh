#!/bin/bash

MAXOBJ=20000
MAXCAPACITE=5000
MAXPOIDSOBJ=600


for i in {1..100}
do
	nbObj=$[1 + $[$RANDOM % $MAXOBJ]]
	capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
	
	echo "$nbObj" >> data/data_$i
	echo "$capacite" >> data/data_$i
		

	for (( j=1; j<=$nbObj; j++ ))
	do
		poids=$[1 + $[$RANDOM % $capacite]]
		echo $poids >> data/data_$i
	done

done
