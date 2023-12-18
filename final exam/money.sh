#!/bin/bash

# Compile the C program with the math library
gcc -o money money.c -lm

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Loop from 1 to 10 and run the program, saving the output to money.txt
    > money.txt  # Clear the file before writing
    for i in {1..10}
    do
       ./money $i >> money.txt
    done
else
    echo "Compilation failed."
fi

