#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main()
{
    int fd;
    char buffer[BUFSIZ];

    // Open FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read messages from FIFO
    while (1)
    {
        ssize_t num_bytes = read(fd, buffer, BUFSIZ);
        if (num_bytes > 0)
        {
            buffer[num_bytes] = '\0';  // Null-terminate string
            printf("Reader (PID %d) received: %s", getpid(), buffer);
        }

        if (strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }
    }

    close(fd);
    return 0;
}
