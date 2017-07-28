#!/bin/sh
CMD=`ifconfig | grep "inet " | cut -d' ' -f2`
NUM=`ifconfig | grep "inet " | cut -d' ' -f2 | wc -l | tr -d ' '`

if [ "$NUM" -eq "2" ]; then
	echo "Je suis perdu!"
else
	echo "$CMD"
fi
