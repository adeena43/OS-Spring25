#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* print_table(void* arg)
{
    int num = *(int*) arg;
    printf("table of %d: \n", num);
    for(int i = 0; i<1000/num; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    printf("End of table %d\n\n", num);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[4];
    int nums[4] = {5,6,7,8};

    for(int i = 0; i<4; i++)
    {
        pthread_create(&threads[i], NULL, print_table, &nums[i]);
    }
    for(int i = 0; i<4; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}