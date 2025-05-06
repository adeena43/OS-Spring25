#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main() {
    float *A, *B, *C;
    A = (float *)malloc(SIZE * sizeof(float));
    B = (float *)malloc(SIZE * sizeof(float));
    C = (float *)malloc(SIZE * sizeof(float));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = i * 2.0f;
    }

    // Perform C = A + B operation
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Serial computation completed.\n");

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}
