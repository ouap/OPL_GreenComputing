#!/bin/bash

files=$(ls result)
IFS=$'\n'

for file in $files
do
	t=0;
	echo $file
	for line in $(cat result/$file)
	do
		power=`echo $line | cut -f 1 -d " " | cut -f 5 -d ";" | cut -f 2 -d "=" `
		#echo "$t, $power " #>> result/format_$file

		sed -i '' "s/${line}/$t  $power/g" result/$file
		t=$(($t+20))
	done
done