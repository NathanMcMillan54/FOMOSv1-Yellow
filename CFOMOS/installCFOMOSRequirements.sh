#!/usr/bin/env bash

echo "Updating OS..."
sudo apt-get update
sudo apt-get install

echo "Installing GTK..."
sudo apt-get install libgtk-3-dev

echo "Installing Network-Manager..."
sudo apt-get install network-manager

echo "Installing Matchbox-Keyboard..."
sudo apt-get install network-manager

echo "Installing x-term teminal..."
sudo apt-get install xterm
