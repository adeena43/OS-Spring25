#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pipefd[2];
    int pid;
    char buffer[15];
    pipe(pipefd);
    pid = fork();

    if(pid > 0)
    {
        fflush(stdin);
        printf("Unnamed pipe [INFO] Parent process\n");
        write(pipefd[1], "Hello Adina", 15);
    }
    else if(pid == 0)
    {
        sleep(5);
        fflush(stdin);
        printf("Unnamed pipe [INFO] Child Process\n");
        read(pipefd[0], buffer, sizeof(buffer));
        write(1,buffer, sizeof(buffer));
        printf("\n");
    }
    else{
        printf("Unnamed pipe [ERROR] Error in creating child process\n");

    }
    if(pid>0)
    {
        wait(NULL);
    }
    return 0;
}