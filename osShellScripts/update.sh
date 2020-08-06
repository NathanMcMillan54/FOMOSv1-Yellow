#!/usr/bin/env bash

echo "Checking for update..."
echo "If there is an update restart this device"
git pull

sh ../installRequirements.sh
