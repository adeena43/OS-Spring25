#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent: Child has finished listing files.\n");
    }

    return 0;
}
