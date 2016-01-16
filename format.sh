#!/bin/bash

exec 1> data.out

i=0
flag=false
for line in $(cat powerapi.out)
do
  if $flag
  then
    flag=false
    continue
  fi

  power=`echo $line | cut -f 5 -d ";" | cut -f 2 -d "="`
  echo "$i $power"
  let "i=i+1"
  flag=true
done