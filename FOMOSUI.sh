#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o FOMOSUI homeScreenUI.c `pkg-config --libs gtk+-3.0`
./FOMOSUI
