```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define NUM_THREADS 10

float *A, *B, *C;

void* vector_add(void* arg) {
    int thread_id = *(int*)arg;
    int chunk_size = SIZE / NUM_THREADS;
    int start = thread_id * chunk_size;
    int end = (thread_id == NUM_THREADS - 1) ? SIZE : start + chunk_size;

    for (int i = start; i < end; i++) {
        C[i] = A[i] + B[i];
    }

    pthread_exit(NULL);
}

int main() {
    A = (float*)malloc(SIZE * sizeof(float));
    B = (float*)malloc(SIZE * sizeof(float));
    C = (float*)malloc(SIZE * sizeof(float));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize A and B
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = i * 2.0f;
    }

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, vector_add, (void*)&thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Concurrent computation completed with %d threads.\n", NUM_THREADS);

    free(A);
    free(B);
    free(C);

    return 0;
}

```
![Q1(b)_postlab](https://github.com/user-attachments/assets/c7af30ae-75ee-4038-adac-da584d26dd5e)
