#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define PRODUCER_COUNT 2
#define CONSUMER_COUNT 2

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

// Producer function
void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100; // Produce an item
        sem_wait(&empty);    // Decrement empty count
        pthread_mutex_lock(&mutex); // Enter critical section

        buffer[in] = item;
        printf("Producer %ld produced %d at %d\n", (long)pthread_self(), item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&full);   // Increment full count

        sleep(rand() % 2); // Simulate time
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);    // Decrement full count
        pthread_mutex_lock(&mutex); // Enter critical section

        item = buffer[out];
        printf("Consumer %ld consumed %d from %d\n", (long)pthread_self(), item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&empty);  // Increment empty count

        sleep(rand() % 2); // Simulate time
    }
    return NULL;
}

int main() {
    pthread_t prod[PRODUCER_COUNT], cons[CONSUMER_COUNT];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < PRODUCER_COUNT; i++)
        pthread_create(&prod[i], NULL, producer, NULL);
    for (int i = 0; i < CONSUMER_COUNT; i++)
        pthread_create(&cons[i], NULL, consumer, NULL);

    for (int i = 0; i < PRODUCER_COUNT; i++)
        pthread_join(prod[i], NULL);
    for (int i = 0; i < CONSUMER_COUNT; i++)
        pthread_join(cons[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
