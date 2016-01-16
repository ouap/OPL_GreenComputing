#!/bin/bash

NBOBJ=50000
MAXCAPACITE=5000
MAXPOIDSOBJ=10000


	nbObj=$NBOBJ
	capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
	
	echo "$nbObj" >> data
	echo "$capacite" >> data
	

	for (( j=1; j<=$nbObj; j++ ))
	do
		poids=$[1 + $[$RANDOM % $capacite]]
		echo $poids >> data
	done

