#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    int fd[2];
    int pid;
    char buffer[BUFSIZ];
    pipe(fd);
    pid = fork();
    if(pid == 0)
    {
        printf("hi, i am the child process\n");
        close(fd[0]);
        fflush(stdin);
        write(fd[1], "'Message recieved from child to parent'\n", 39);
        close(fd[1]);
        printf("Child terminated\n");
        printf("Message written successfully\n");
    }
    else if(pid > 0)
    {
        printf("Hi, i am the parent process\n");
        close(fd[1]);
        wait(NULL);
        fflush(stdin);
        read(fd[0], buffer, sizeof(buffer));
        printf("In the parent process, displaying the message recieved from child\n");
        printf("%s", buffer);
        close(fd[0]);
        printf("\nParent terminating\n");
    }
    else{
        printf("Fork failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}