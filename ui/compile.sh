#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o ui/FOMOSUI ui/FOMOSUI.c `pkg-config --libs gtk+-3.0`
gcc `pkg-config --cflags gtk+-3.0` -o ui/settings ui/settings.c `pkg-config --libs gtk+-3.0`
