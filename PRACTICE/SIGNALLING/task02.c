#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void create_folder(int sig) {
    const char* folder_name = "folder_@_#_!";
    if (mkdir(folder_name, 0777) == 0) {
        printf("Folder '%s' created successfully.\n", folder_name);
    } else {
        perror("Failed to create folder");
    }
}

int main() {
    signal(SIGUSR1, create_folder);  // Parent registers signal handler

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child
        sleep(1);  // Give time for parent to setup signal handler
        kill(getppid(), SIGUSR1);  // Send signal to parent
        exit(0);
    } else {
        // Parent waits for signal
        pause();
    }

    return 0;
}
