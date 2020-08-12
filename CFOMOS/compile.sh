#!/usr/bin/env bash

echo "Compiling FOMOSUI.c"
gcc `pkg-config --cflags gtk+-3.0` -o FOMOSUI FOMOSUI.c `pkg-config --libs gtk+-3.0`
echo "Compiling settings.c"
gcc `pkg-config --cflags gtk+-3.0` -o settings settings.c `pkg-config --libs gtk+-3.0`
echo "Compiling shutdown.c"
gcc -Wall shutdown.c -o shutdown
echo "Compiling restart.c"
gcc -Wall restart.c -o restart
