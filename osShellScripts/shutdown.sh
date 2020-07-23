#!/usr/bin/env bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Shutting down..."
    shutdown -P now
else
    echo "Shutdown doesn't work on this OS"
fi
