#!/bin/bash

# Compile the C program
gcc -o trap trap.c -lm

# Run the program for different values of N and save the output
> trap.txt  # Clear the file before writing
for N in 10 20 50 100 1000
do
   ./trap $N >> trap.txt
done

