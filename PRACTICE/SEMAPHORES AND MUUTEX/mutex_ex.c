#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

int shared_dta = 0;
pthread_mutex_t mutex;

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);

    pthread_mutex_lock(&mutex);
    shared_dta++;
    printf("Thread %d incremented shared_dta to %d\n", thread_id, shared_dta);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;

        // ❌ FIXED: was using &threads instead of &threads[i]
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("Thread creation failed");
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("Final value of shared_dta = %d\n", shared_dta);

    return 0;
}
