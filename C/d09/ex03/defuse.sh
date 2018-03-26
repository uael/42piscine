#!/bin/sh
touch -t $(date -v-1S -r $(stat -f %m  bomb.txt) +%Y%m%d%H%M.%S) bomb.txt && echo $(stat -f %m  bomb.txt)
