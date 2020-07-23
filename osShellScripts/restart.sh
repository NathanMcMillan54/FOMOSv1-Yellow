#!/usr/bin/env bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Restarting..."
    restart
else
    echo "Restart doesn't work on this OS"
fi
