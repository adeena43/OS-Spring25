#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open the file input.txt for reading and writing
    fd = open("input.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    // Read the contents of the file into the buffer
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }
    buffer[bytesRead] = '\0'; // Null-terminate the buffer

    printf("Parent Process: Read content from file:\n%s\n", buffer);

    // Create a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(1);
    } 
    else if (pid == 0) { 
        // Child process
        printf("Child Process: Modifying the file content...\n");

        // Move the file pointer to the beginning
        lseek(fd, 0, SEEK_SET);

        // Write new content to the file
        const char *newContent = "Processed by child process\n";
        if (write(fd, newContent, 26) == -1) {
            perror("Error writing to file");
            close(fd);
            exit(1);
        }
        close(fd);

        // Use execlp() to replace the child process with `cat input.txt`
        execlp("cat", "cat", "input.txt", NULL);

        // If execlp() fails
        perror("execlp failed");
        exit(1);
    } 
    else { 
        // Parent process waits for child to complete
        wait(NULL);
        printf("Parent Process: Child process finished execution.\n");
    }

    close(fd);
    return 0;
}
