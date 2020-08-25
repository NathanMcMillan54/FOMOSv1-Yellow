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
elif [ "$input" = "Y" ]; then
  echo "Restarting and adding FOMOS GUI..."
  reboot
elif [ "$input" = "n" ]; then
    echo "Restart your device soon."
elif [ "$input" = "N" ]; then
    echo "Restart your device soon."
else
  # if u thought i (Nathan McMillan) would make something to ask
  # the question again then u was wrong
  echo "You didn't input y or n"
fi
