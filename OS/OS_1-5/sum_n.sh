#!/bin/bash
# Experiment 2b - Sum of N Numbers

echo "Enter limit"
read n

i=1
sum=0

while [ $i -le $n ]
do
    let sum=$sum+$i
    let i=$i+1
done

echo "The sum of $n numbers is $sum"
