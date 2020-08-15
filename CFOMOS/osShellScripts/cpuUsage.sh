#!/usr/bin/env bash

top -bn1 | grep load | awk '{printf "CPU Load: %.2f\n", $(NF-2)}'
