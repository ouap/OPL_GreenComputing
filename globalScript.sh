#!/bin/bash

chmod 755 scriptJava.sh scriptC.sh scriptPython.sh format.sh getPlots.sh

rm binpackJava/result/*
rm binpackC/result/*
rm binpackPython/result/*
#Execution
javac Sort.java
java Sort result

./scriptJava.sh
./scriptC.sh
./scriptPython.sh


./format.sh
./getPlots.sh




