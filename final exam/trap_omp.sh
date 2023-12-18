#!/bin/bash

# Compile the OpenMP version of the program
gcc -fopenmp -o trap_omp trap_omp.c -lm

# Run the program for different values of N with 4 threads and save the output
> trap_omp.txt  # Clear the file before writing
for N in 10 20 50 100 1000
do
   ./trap_omp $N 4 >> trap_omp.txt
done

