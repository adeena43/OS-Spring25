#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

void compute_sum(int n){
    int sum = (n*(n+1)) / 2;
    printf("the sum of the first %d integers is %d\n", n, sum);
}

void compute_cube(int n)
{
    printf("the cube of %d is %d\n", n, n*n*n);
}

void compute_square(int n)
{
    printf("the cube of %d is %d\n", n, n*n);
}

int main()
{
    FILE *file = fopen("data.txt", "w");
    if(file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "10 2 7\n");
    fclosef(file);

    int numbers[3];
    file = fopen("data.txt", "r");
    if(file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d %d %d", &numbers[0], &numbers[1], &numbers[2]);
    fclose(file);

    for(int i = 0; i<3; i++)
    {
        pid_t pid = fork();
        if(pid<0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if(pid == 0)
        {
            if(i==0)
            {
                compute_sum(numbers[0]);
            }
            else if(i==1)
            {
                compute_cube(numbers[1]);
            }
            else
            {
                compute_square(numbers[2]);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
