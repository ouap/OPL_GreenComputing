#!/bin/bash

NBOBJ=50000
MAXCAPACITE=20000
MAXPOIDSOBJ=10000


for i in {1..5}
do
	nbObj=$NBOBJ
	capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
	
	echo "$nbObj" >> data/data_$i
	echo "$capacite" >> data/data_$i
	

	for (( j=1; j<=$nbObj; j++ ))
	do
		poids=$[1 + $[$RANDOM % $capacite]]
		echo $poids >> data/data_$i
	done

done
