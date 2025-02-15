#!/bin/bash

echo "Enter the filename:"
read filename

if [ -f "$filename" ]; then
	current_datetime=$(date)

	echo "$current_datetime" >> "$filename"
	echo "Date and time appended to $filename"
else
	echo "Error: File '$filename' does not exist"

fi
