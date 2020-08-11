#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o FOMOSUI FOMOSUI.c `pkg-config --libs gtk+-3.0`
gcc `pkg-config --cflags gtk+-3.0` -o settings settings.c `pkg-config --libs gtk+-3.0`
gcc -Wall shutdown.c -o shutdown
gcc -Wall restart.c -o restart
