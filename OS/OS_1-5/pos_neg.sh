#!/bin/bash
# Experiment 2d - Check Whether Number is Positive or Negative

echo "Enter a number"
read a

if [ $a -ge 0 ]
then
    echo "$a is positive"
else
    echo "$a is negative"
fi
