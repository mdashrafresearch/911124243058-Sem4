#!/bin/bash
# Experiment 2c - Swapping of Two Numbers

echo "Enter two numbers"
read a b

t=$a
a=$b
b=$t

echo "After swapping: a=$a b=$b"
