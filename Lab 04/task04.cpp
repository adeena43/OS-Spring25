#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int input_fd, output_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    input_fd = open("input.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input.txt");
        return 1;
    }

    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("Error opening output.txt");
        close(input_fd);
        return 1;
    }

    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        write(output_fd, buffer, bytes_read);
    }

    close(input_fd);
    close(output_fd);
    printf("File copied successfully.\n");

    return 0;
}
