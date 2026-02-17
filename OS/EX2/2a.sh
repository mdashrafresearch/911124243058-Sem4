#!/bin/bash
echo "Enter 2 numbers"
read a b

if [ $a -gt $b ]
then
    echo "$a is greater"
else
    echo "$b is greater"
fi
