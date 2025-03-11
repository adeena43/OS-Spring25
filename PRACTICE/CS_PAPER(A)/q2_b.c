#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

double find_median(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = i; j< n; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    if(n%2 == 0)
    {
        return (arr[n/2 - 1]+arr[n/2]) / 2.0;
    }
    else{
        return arr[n/2];
    }
}
long int factorial(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int main()
{
    int pipe1[2], pipe2[2];
    pid_t pid;

    pipe(pipe1);
    pipe(pipe2);

    if(pipe(pipe1)==-1 || pipe(pipe2)==-1)
    {
        perror("Pipe failed");
        exit(1);
    }
    pid = fork();

    if(pid == 0)
    {
        close(pipe1[1]);
        close(pipe2[0]);

        int arr[100];
        int n;
        read(pipe1[0], &n, sizeof(int));
        read(pipe1[0], arr, sizeof(int) * n);

        double median = find_median(arr, n);
        int med = (int)median;

        write(pipe2[1], &med, sizeof(med));

        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    }
    else
    {
        close(pipe1[0]);
        close(pipe2[1]);

        int arr[] = {1,5,2,3,7,8,10};
        int n = 7;

        write(pipe1[1], &n, sizeof(n));
        write(pipe1[1], arr, sizeof(int) * n);

        int median;

        read(pipe2[0], &median, sizeof(median));

        long int fact = factorial(median);
        printf("Median: %d\n", median);
        printf("factorial: %d\n", fact);

        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    }
    return 0;
}
