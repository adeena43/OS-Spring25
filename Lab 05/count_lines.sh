#!/bin/bash

echo -n "Enter the filename:"
read filename

if [ ! -f "$filename" ]; then
	echo "Error: file does not exist"
	exit 1
fi

line_count=$(wc -l < "$filename")

echo "The file $filename has $line_count lines"
