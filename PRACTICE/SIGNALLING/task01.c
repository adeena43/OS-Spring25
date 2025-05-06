#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<time.h>

#define SIZE 10
int arr[SIZE];
int interrupted = 0;

void signal_handler(int sigint)
{
    interrupted = 1;
    printf("\n\nSIGINT recieved! Current array state: ");
    for(int i = 0; i<SIZE; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    exit(0);
}

void generate_array()
{
    for(int i = 0; i<SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
}

void print_array()
{
    for(int i = 0; i<SIZE; i++)
    {
        printf("%d, ", arr[i]);
        
    }
    printf("\n");
}

void bubbleSort_withDelay()
{
    for(int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j<SIZE - i- 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                sleep(1);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            if(interrupted){
                return;
            }
        }
    }
}
int main()
{
    signal(SIGINT, signal_handler);

    generate_array();
    printf("Original array:\n");
    print_array();

    printf("Sorting started... Press Ctrl+C to interrupt.\n");
    bubbleSort_withDelay();

    printf("\nFinal sorted array:\n");
    print_array();
    return 0;
}