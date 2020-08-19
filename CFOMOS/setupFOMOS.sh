#!/usr/bin/env bash

echo "Updating FOMOS..."
sh osShellScripts/updateCFOMOS.sh

echo "Installing requirements..."
sh installCFOMOSRequirements.sh

echo "Moving files..."
# this will be moving any files that need to be moved

echo "Setup is finished."
echo "Restart is needed to apply changes."
echo "Is it ok to restart now?"

read -p "Is it ok to restart now? (y/n) " input
if [ "$input" = "y" ]; then
  echo "Restarting and adding FOMOS GUI..."
  reboot
else
  echo "Restart your device soon."
fi
