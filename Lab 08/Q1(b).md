```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREADS 10

float *A, *B, *C;

typedef struct {
    int start, end;
} ThreadData;


void *compute_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->start; i < data->end; i++) {
        C[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    ThreadData thread_data[THREADS];

    A = (float *)malloc(SIZE * sizeof(float));
    B = (float *)malloc(SIZE * sizeof(float));
    C = (float *)malloc(SIZE * sizeof(float));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = i * 2.0f;
    }

    int chunk_size = SIZE / THREADS;
    for (int i = 0; i < THREADS; i++) {
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == THREADS - 1) ? SIZE : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, compute_sum, &thread_data[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Parallel computation with %d threads completed.\n", THREADS);

    free(A);
    free(B);
    free(C);

    return 0;
}

```
![Q1(b)_postlab](https://github.com/user-attachments/assets/c7af30ae-75ee-4038-adac-da584d26dd5e)
