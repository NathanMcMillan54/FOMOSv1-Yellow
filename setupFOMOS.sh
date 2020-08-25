#!/usr/bin/env bash

echo "Updating FOMOS..."
sh osShellScripts/updateCFOMOS.sh

echo "Installing requirements..."
sh installFOMOSRequirements.sh

echo "Moving files..."

echo "Current user $USER"

cd ~//../../
mv /home/$USER/Desktop/FOMOSv1-Yellow/startFOMOS.sh ~//../../etc/profile.d/


echo "Setup is finished."
echo "Restart is needed to apply changes."

read -p "Is it ok to restart now? (y/n) " input
if [ "$input" = "y" ]; then
  echo "Restarting and adding FOMOS GUI..."
  reboot
else
  echo "Restart your device soon."
fi
