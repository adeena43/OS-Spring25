#!/bin/bash

echo "Enter the filename or directory name:"
read input_name

if [ -e "$input_name" ]; then
	if [ -f "$input_name" ]; then
		echo "$input_name is a file"
	elif [ -d "$input_name" ]; then
		echo "$input_name is a directory"
	else
		echo "$input_name is not a regular file or directory"
	fi
else
	echo "$input_name does not exist."
fi
