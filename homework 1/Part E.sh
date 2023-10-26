#!/bin/bash
trials=10
# Run the program 10 times
for i in $(seq 1 $trials); do
    echo "Trial $i"
    ./montecarlo >> output_$i.dat
done
