#!/bin/bash

# Compile the C program
gcc -o montecarlo montecarlo.c -lm

# Number of trials
trials=10

# Run the program 10 times
for i in $(seq 1 $trials); do
    echo "Trial $i"
    ./montecarlo >> results_$i.dat
done

