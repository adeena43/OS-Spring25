#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "myfifo"

int main()
{
    int fd;
    char buffer[1024];
    ssize_t num_bytes;

    // Ensure mkfifo is properly declared
    if (mkfifo(FIFO_FILE, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for consumer to connect...\n");
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("Consumer connected. Ready to send messages.\n");

    while (1) {
        printf("Producer: Enter a message (or 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        num_bytes = write(fd, buffer, strlen(buffer));
        if (num_bytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(fd);
    unlink(FIFO_FILE);
    return 0;
}

	
