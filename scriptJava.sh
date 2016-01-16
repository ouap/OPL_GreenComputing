#!/bin/bash

NBOBJ=(10000 25000 50000)
methods=(fist next best)
sleep=(3 3 3)
i=0

javac *.java

for nb in ${$NBOBJ[@]}
do
	for method in ${$methods[@]}
	do
		java SolutionWalkerBinPackXX ../data/data_$nb_1 $method &

		VAR=$!
		../powerapi-iagl-3.3/bin/powerapi 84 100 $VAR &
		powerapi=$!
		sleep ${sleep[0]}
		kill $powerapi
		mv powerapi.out result/powerapi_java_data${nb}_${method}.out
		rm powerapi.out

	done

done

#
#jobs &>/dev/null
#./GreenComputing_C/a.out &
#new_job_started="$(jobs -n)"
#if [ -n "$new_job_started" ];then
#    VAR=$!
#else
#    VAR=
#fi
#echo $VAR
#./powerapi-iagl-3.3/bin/powerapi 28 $VAR
#mv powerapi.out powerapi_c.out