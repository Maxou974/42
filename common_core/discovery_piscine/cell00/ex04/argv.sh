#!/bin/bash
if [ $# == 0 ]
then
	echo "No args"
fi
for ((c=1; c<=$#; c++))
do
	echo "${!c}"
done
