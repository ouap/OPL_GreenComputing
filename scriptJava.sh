#!/bin/bash

NBOBJ=(50000 75000 100000)
methods=(first next best)
sleep=(3 3 3 3 3 4 5 2 5)
i=0

cd binpackJava

javac *.java

for nb in ${NBOBJ[@]}
do
	for method in ${methods[@]}
	do
		java SolutionWalkerBinPackXX ../data/data_${nb}_1 $method &
		VAR=$!
		../powerapi-iagl-3.3/bin/powerapi 84 20 $VAR &
		powerapi=$!
		sleep ${sleep[i]}
		let i++
		kill $powerapi
		mv powerapi.out ../result/powerapi_java_data${nb}_${method}.out
	done

done

cd ../
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
