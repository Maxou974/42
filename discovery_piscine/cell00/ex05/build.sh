#!/bin/bash
for ((c=1; c<=$#; c++))
do
	mkdir "ex${!c}"
done