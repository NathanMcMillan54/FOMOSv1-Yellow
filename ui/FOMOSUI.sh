#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o FOMOSUI FOMOSUI.c `pkg-config --libs gtk+-3.0`
./FOMOSUI
