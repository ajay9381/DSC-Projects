#!/bin/bash
MYPID=30
echo "PID IS" $MYPID
ps −p $MYPID −o comm # this will display the process name
while [ "1" == "1" ] # trick to keep the loop running
do
x=`date +%s` # this will grab the current time from your computer
y=`ps -p 30 -o %cpu | tail -n 1 `
sleep 1 # pause for 1 second
echo $x $y # print the current time and CPU usage
done
~       
