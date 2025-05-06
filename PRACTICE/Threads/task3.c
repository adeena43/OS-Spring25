#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BATCH_SIZE 4  // You can change this to 5 if you prefer

typedef struct {
    int thread_id;
    int iteration;
} ThreadData;

void* thread_function(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    printf("Hello from thread %d - I was created in iteration %d\n", data->thread_id, data->iteration);
    free(data);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    pthread_t threads[N];
    int thread_count = 0;
    int iteration = 0;

    while (thread_count < N) {
        int threads_this_batch = (N - thread_count >= BATCH_SIZE) ? BATCH_SIZE : (N - thread_count);

        for (int i = 0; i < threads_this_batch; i++) {
            ThreadData* data = malloc(sizeof(ThreadData));
            data->thread_id = thread_count + 1;
            data->iteration = iteration;

            printf("I am thread 1. Created new thread (%d) in iteration %d...\n", data->thread_id, iteration);
            if (pthread_create(&threads[thread_count], NULL, thread_function, data) != 0) {
                perror("Failed to create thread");
                free(data);
            }

            thread_count++;
        }

        sleep(1); // Sleep main thread for 1 second
        iteration++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
