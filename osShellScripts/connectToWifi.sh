#!/usr/bin/env bash

ssid=$1
password=$2

echo "Connected to $1"

sudo nmcli dev wifi connect ${ssid} password ${password}
