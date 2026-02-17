#!/bin/bash
echo "Enter limit"
read n

i=1
sum=0

while [ $i -le $n ]
do
    sum=$((sum + i))
    i=$((i + 1))
done

echo "The sum of $n numbers is $sum"

