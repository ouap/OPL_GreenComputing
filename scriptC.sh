#!/bin/bash

cd binpackC

make

for i in {1..5}
do

./binPack ../data/data_$i &

VAR=$!
../powerapi-iagl-3.3/bin/powerapi 84 100 $VAR &
powerapi=$!
sleep 10
kill $powerapi
mv powerapi.out powerapi_c_data$i.out

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