#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }

    printf("Enter the message to pass from parent to child: ");
    fgets(write_msg, BUFFER_SIZE, stdin);
    write_msg[strcspn(write_msg, "\n")] = '\0';  // Remove newline character

    pid = fork(); // Creating a new process

    if (pid < 0) {
        fprintf(stderr, "Fork failed, could not create a child process\n");
        return 1;
    }

    if (pid > 0) { // Parent Process
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);

        close(fd[READ_END]);  // Close unused read end
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]); // Close write end after writing
    } 
    else {  // Child Process
        printf("Child Process Running...\n");
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID in Child: %d\n", getppid());

        close(fd[WRITE_END]);  // Close unused write end
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Read in the child process (message from parent): %s\n", read_msg);
        close(fd[READ_END]); // Close read end
    }

    return 0;
}
