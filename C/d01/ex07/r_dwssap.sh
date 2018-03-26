#!/bin/sh
cat /etc/passwd | grep '^[A-Za-z_]' | sed -n 'n;p' | sed 's/:.*//g' | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | paste -sd, - | sed 's/,/, /g' | sed 's/\(.*\)/\1./' | tr -d '\n'
