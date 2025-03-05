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

    if (mkfifo(FIFO_FILE, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for producer to connect...\n");
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("Producer connected. Ready to receive messages.\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer)); 
        num_bytes = read(fd, buffer, sizeof(buffer) - 1); 

        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (num_bytes == 0) {
            printf("Producer has closed the connection.\n");
            break;
        }

        buffer[num_bytes] = '\0'; 
        printf("Consumer received: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(fd);
    unlink(FIFO_FILE); 
    return 0;
}

	
