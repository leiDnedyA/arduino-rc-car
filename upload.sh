#!/bin/bash

# Compiles & uploads the sketch

if [ $# -eq 0 ]; then
    echo "No board port argument provided."
    echo "To find your board's port, run 'arduino-cli board port'"
    echo 'Example: "./upload.sh /dev/ttyACM0"'
    exit 1
fi

arduino-cli compile --fqbn arduino:avr:uno .
arduino-cli upload -p $1 --fqbn arduino:avr:uno .

exit 0
