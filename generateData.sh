#!/bin/bash

nbObj=(10000 25000 50000)
MAXCAPACITE=20000
CAPACITE=20000

for nb in ${nbObj[@]}
do

	for i in {1..5}
	do
		#capacite=$[1 + $[$RANDOM % $MAXCAPACITE]]
		
		echo "$nb" >> data/data_${nb}_$i
		echo "$CAPACITE" >> data/data_${nb}_$i		

		for (( j=1; j<=$nb; j++ ))
		do
			poids=$[1 + $[$RANDOM % $CAPACITE]]
			echo $poids >> data/data_${nb}_$i
		done

	done
done

