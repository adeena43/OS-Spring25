#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
#define NUM_READERS 5
#define NUM_WRITERS 2
sem_t mutex, rw_mutex;
pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
int readers_count = 0;
FILE* file;

char generateRandomChar()
{
    return (char) ('a' + rand() % 26);
}

void *reader(void *arg)
{
    while(1)
    {
        sem_wait(&mutex);
        readers_count++;
        if(readers_count == 1)
        {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        fseek(file, 0, SEEK_SET);
        char buffer[256];
        while(fgets(buffer, sizeof(buffer), file)!=NULL){
            fprintf(stdout, "Reader: %s", buffer);
        }

        sem_wait(&mutex);
        readers_count--;
        if(readers_count==0)
        {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);
    }
}
int main()
{

}