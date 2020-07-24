#!/usr/bin/env bash

df -h | awk '$Nf=="/"{printf "Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}'
free -m | awk 'NR==2{printf "Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'
top -bn1 | grep load | awk '{printf "CPU Load: %.2f\n", $(NF-2)}'
