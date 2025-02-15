#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 <directory path>"
	exit 1
fi

dir_to_backup="$1"

if [ ! -d "$dir_to_backup" ]; then
	echo "Error: $dir_to_backup is not a valid directory"
	exit 1
fi

backup_dir = "backup_$(date +%Y-%m-%d_%H-%M-%S)"
mkdir -p "backup_dir"

rsync -av --progress "$dir_to_backup/" "$backup_dir/"

file_count=$(find "$backup_dir" -type f | wc -l)
dir_count=$(find "$backup_dir" -type d | wc -l)

echo "Backup completed successfully"
echo "Backup location: $backup_dir"
echo "Files backed up: $file_count"
echo "Directories backed up: $dir_count"
