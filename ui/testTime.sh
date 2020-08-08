#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o testTime testTime.c `pkg-config --libs gtk+-3.0`
./testTime
