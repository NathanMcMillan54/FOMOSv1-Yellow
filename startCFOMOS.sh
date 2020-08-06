#!/usr/bin/env bash

gcc `pkg-config --cflags gtk+-3.0` -o FOMOS FOMOS.c `pkg-config --libs gtk+-3.0`
./FOMOS
