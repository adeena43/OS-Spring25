#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int fd;
    ssize_t num_bytes;
    char buffer[BUFSIZ];
    mkfifo("myFifo", 0666);
    fd = open("myFifo", O_WRONLY);
    if(fd==-1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("Write a message (write exit to terminate): ");
        fgets(buffer, BUFSIZ, stdin);
        write(fd, buffer, strlen(buffer));
        if(strncmp(buffer, "exit", 4)==0)
        {
            break;
        }
    }
    close(fd);
    unlink("myFifo");
    return 0;
}