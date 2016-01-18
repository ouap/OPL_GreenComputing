#!/bin/bash

NBOBJ=(50000 75000 100000)
methods=(first next best)
sleep=(41 1 50 96 1 112 165 1 200)
i=0

cd binpackPython


for nb in ${NBOBJ[@]}
do
	for method in ${methods[@]}
	do
		python binPack.py ../data/data_${nb}_1 $method &

		VAR=$!
		../powerapi-iagl-3.3/bin/powerapi 84 500 $VAR &
		powerapi=$!
		sleep ${sleep[i]}
		kill $powerapi
		mv powerapi.out ../result/powerapi_python_data${nb}_${method}.out

		let i++
	done
done

cd ..

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
