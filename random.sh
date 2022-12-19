#!/bin/bash
declare -i a=0
declare -i b=0
declare -i max=0
for ((n=0;n<20;n++))
do

echo "##### $n #####"
ARG=`ruby random.ruby $1`
./push_swap "$ARG" | ./checker "$ARG"

a=($(./push_swap "$ARG" | wc -l))
echo $a
b=$((b+a))

if [ $a -gt $max ] ; then
	max=$a
else
	:
fi

echo - "$ARG" ------

done
b=$((b/n))
echo "average = $b"
echo "max = $max"
