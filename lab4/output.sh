#!/bin/bash

# Remove any existing data file
rm -f trapezoidal_data.txt

i=1
while [ $i -le 30 ]
do
  echo "Running N = $((2**i))"
  result=$(./trap $((2**i)))
  echo "$((2**i)) $result" >> trapezoidal_data.txt
  ((i++))
done

