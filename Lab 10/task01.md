```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  // for sleep()

#define BUFFER_SIZE 5

sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random item to produce
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(rand() % 3); // Simulate some processing time
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(rand() % 3); // Simulate some processing time
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

```
# a)
![code1](https://github.com/user-attachments/assets/83d1b025-59cc-4ce1-a252-c89036b79da4)

# b)
    In this code, the full and empty semaphores are basically used to keep track of the buffer status. 
    empty tells how many empty spots are left in the buffer where the producer can put items, and full 
    tells how many spots are already filled and ready for the consumer to take items from. When the producer adds an item, 
    it decreases the empty count and increases the full count. When the consumer takes an item out, it does the opposite 
    — it decreases full and increases empty. 
    This way, the producer won't overfill the buffer, and the consumer won’t try to take something when there’s nothing there.
# c)
    The sleep() function in the producer and consumer is just there to slow things down a little and make it look more realistic. 
    Instead of the producer and consumer running very fast (like how computers normally work), sleep() makes them wait for a 
    random amount of time between 0 and 2 seconds. This way, the producer doesn't fill the buffer instantly, and the consumer 
    doesn't empty it instantly either. It helps create a more natural flow and makes it easier to see what's actually happening 
    when we run the program.
