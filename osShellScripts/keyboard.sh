#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    matchbox-keyboard
else
    echo "Can't open keyboard"
fi

