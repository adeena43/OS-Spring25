#!/bin/bash

# Function to display all running processes
view_processes() {
    echo "Running Processes:"
    ps -e
}

# Function to search for a process by name
search_process() {
    read -p "Enter process name to search: " pname
    pgrep "$pname"
    if [ $? -ne 0 ]; then
        echo "No process found with the name: $pname"
    fi
}

# Function to kill a process by PID
kill_process() {
    read -p "Enter PID to kill: " pid
    if ps -p $pid > /dev/null; then
        kill $pid
        echo "Process $pid terminated."
    else
        echo "No process found with PID $pid."
    fi
}

# Function to check system resource usage
check_resources() {
    echo "CPU and Memory Usage:"
    free -m
    uptime
}

# Menu-driven loop
while true; do
    echo "\nSystem Process Manager"
    echo "1. View Running Processes"
    echo "2. Search Process by Name"
    echo "3. Kill Process by PID"
    echo "4. Check System Resource Usage"
    echo "5. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1) view_processes ;;
        2) search_process ;;
        3) kill_process ;;
        4) check_resources ;;
        5) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid choice, please try again." ;;
    esac
done
