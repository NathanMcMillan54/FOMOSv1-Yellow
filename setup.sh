#!/bin/bash

echo "Compiling..."
cargo build
echo "Moving..."
mv target/debug/FOMOSv1-Yellow /etc/profile.d/
