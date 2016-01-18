#!/bin/bash

cd result
for file in $(ls)
do
	lang=`echo "$file" | cut -f 2 -d "_" `
	data=`echo "$file" | cut -f 3 -d "_"  `
	method=`echo "$file" | cut -f 4 -d "_" | cut -f 1 -d "." `
	name=`echo "$file" | cut -f 1 -d "." `.png

	echo "set terminal png size 1024,768 enhanced font \"Helvetica,20\"
set key outside bottom center
set autoscale fix
set output \"${name}\"
set xlabel \"Time (ms)\"
set ylabel \"Power (mW)\"
set title \"Power usage for $method method in $lang with $data \"
plot \"$file\" with lines" > plot.conf

	gnuplot plot.conf
done
mkdir c java python
mv powerapi_c_data*.png c/
mv powerapi_java_data*.png java/
mv powerapi_python_data*.png python/
rm plot.png
cd ..
