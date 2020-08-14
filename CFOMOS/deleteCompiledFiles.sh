#!/usr/bin/env bash

# this file is only for developers who are adding stuff to FOMOS on github
# don't add the file format to these lines because it will delete the actual file

echo "Deleting compiled files..."
echo "  "
rm -rf FOMOS
rm -rf FOMOSUI
rm -rf settings
rm -rf shutdown
rm -rf restart
echo "Finished deleting compiled files"
