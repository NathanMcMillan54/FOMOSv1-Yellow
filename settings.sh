#!/usr/bin/env bash

echo "Settings"
gcc `pkg-config --cflags gtk+-3.0` -o settings settings.c `pkg-config --libs gtk+-3.0`
./settings
