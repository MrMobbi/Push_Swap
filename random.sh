#!/bin/bash
declare -i a=0
declare -i b=0
for ((n=0;n<100;n++))
do

echo "##### $n #####"
ARG=`ruby random.ruby $1`
./push_swap "$ARG" | ./check "$ARG"

a=($(./push_swap "$ARG" | wc -l))
echo $a
b=$((b+a))
echo - "$ARG" ------

done
b=$((b/n))
echo "average = $b"
