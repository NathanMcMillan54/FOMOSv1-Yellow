#!/usr/bin/env bash

echo "Getting update..."
git pull

echo "Adding any changes to FOMOS..."
sh ../compile.sh

echo "Restarting..."
reboot
