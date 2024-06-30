#!/bin/bash

usage() {
  echo "Usage: $0 <board port> [--monitor]"
  exit 1
}

BOARD=$1
shift # Remove BOARD from the arg list

MONITOR=false

while [[ "$#" -gt 0 ]]; do
  case $1 in
    --monitor)
      MONITOR=true
      shift # Remove the current argument
      ;;
    *)
      echo "Invalid option: $1" >&2
      usage
      ;;
  esac
done

arduino-cli compile --fqbn arduino:avr:uno .
if [ $? -eq 1 ]; then
  echo "Build failed :("
  exit 1
fi
arduino-cli upload -p $BOARD --fqbn arduino:avr:uno .
if [ $? -eq 1 ]; then
  echo "Upload failed :("
  exit 1
fi

if [ "$MONITOR" = true ]; then
  arduino-cli monitor -p $BOARD
fi

exit 0
