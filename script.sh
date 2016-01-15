#!/bin/bash

jobs &>/dev/null
./GreenComputing_C/a.out &
new_job_started="$(jobs -n)"
if [ -n "$new_job_started" ];then
    VAR=$!
else
    VAR=
fi
echo $VAR
./powerapi-iagl-3.3/bin/powerapi 28 $VAR
mv powerapi.out powerapi_c.out