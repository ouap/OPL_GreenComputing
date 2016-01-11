#!/bin/bash

MAXOBJ=20000
MAXCAPACITE=5000
MAXPOIDSOBJ=600


for i in {1..100}
do
	nbObj=$[1 + $[$RANDOM % $MAXOBJ]]
	capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
	
	echo "$nbObj" >> binpackJava/data/data_$i
	echo "$capacite" >> binpackJava/data/data_$i
	echo "$nbObj" >> binpackC/data/data_$i
 	echo "$capacite" >> binpackC/data/data_$i
	echo "$nbObj" >> binpackPython/data/data_$i
 	echo "$capacite" >> binpackPython/data/data_$i
		

	for (( j=1; j<=$nbObj; j++ ))
	do
		poids=$[1 + $[$RANDOM % $MAXCAPACITE]]
		echo $poids >> binpackJava/data/data_$i
		echo $poids >> binpackC/data/data_$i
		echo $poids >> binpackPython/data/data_$i
	done

done
