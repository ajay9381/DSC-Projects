#!/bin/bash
MYPID=98
echo "PID IS" $MYPID
ps -p $MYPID -o comm # This will display the process name

while [ "1" == "1" ] # Trick to keep the loop running
do
    x=$(date +%s) # This will grab the current time from your computer
    y=$(ps -p $MYPID -o %cpu | tail -n 1)
    sleep 1 # Pause for 1 second
    echo $x $y # Print the current time and CPU usage

    # Correct invocation of MyCommand, assuming it's in the same directory
    ./MyCommand $y
done

