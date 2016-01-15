#!/bin/bash

cd binPackJava
for data in $(ls ../data/)
do
	java SolutionWalkerBinPackXX ../data/$data 
done
